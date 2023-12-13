#include <glut.h>
#include <string>
#include <iostream>

float triangleX = 300;
float triangleY = 220;

float squareX = -280;  // Posisi awal kotak di ujung kiri bawah
float squareY = -220;

bool gameStarted = false;

void startGame() {
    std::cout << "Game started!" << std::endl;
    // Logika permainan dapat ditambahkan di sini
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 13 && !gameStarted) {  // ASCII untuk tombol "Enter"
        gameStarted = true;
        startGame();
    }

    if (gameStarted) {
        switch (key) {
        case 'w':
            squareY += 10;
            break;
        case 's':
            squareY -= 10;
            break;
        case 'a':
            squareX -= 10;
            break;
        case 'd':
            squareX += 10;
            break;
        }
    }

    glutPostRedisplay();
}

void userdraw() {
    glBegin(GL_LINE_LOOP);
    glColor3ub(255, 0, 0);
    glVertex2f(50, 50);
    glVertex2f(175, 50);
    glVertex2f(175, 175);
    glVertex2f(50, 175);
    glEnd();

    glLineWidth(3.0);
    glColor3f(0, 60, 175);
    glRasterPos2f(-130, 0);  // Posisi teks
    const char* teks = "Pilih gambar yang tepat !!";
    for (int i = 0; teks[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, teks[i]);
    }

    glColor3f(0, 185, 90);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, -90);     // Titik atas
    glVertex2f(-60, -170);   // Titik kiri bawah
    glVertex2f(60, -170);    // Titik kanan bawah
    glEnd();

    glColor3f(100, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(triangleX, triangleY + 30);    // Titik atas
    glVertex2f(triangleX - 40, triangleY - 30); // Titik kiri bawah
    glVertex2f(triangleX + 40, triangleY - 30); // Titik kanan bawah
    glEnd();


    glColor3f(0, 225, 0);
    glBegin(GL_QUADS);
    glVertex2f(squareX, squareY);            // Titik kiri bawah
    glVertex2f(squareX + 90, squareY);      // Titik kanan bawah
    glVertex2f(squareX + 90, squareY + 90); // Titik kanan atas
    glVertex2f(squareX, squareY + 90);      // Titik kiri atas
    glEnd();
}

void specialKeys(int key, int x, int y) {
    if (gameStarted) {
        switch (key) {
        case GLUT_KEY_UP:
            triangleY += 10;
            break;
        case GLUT_KEY_DOWN:
            triangleY -= 10;
            break;
        case GLUT_KEY_LEFT:
            triangleX -= 10;
            break;
        case GLUT_KEY_RIGHT:
            triangleX += 10;
            break;
        }
        glutPostRedisplay();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 580);
    glutInitWindowPosition(310, 55);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("UTS SEA DEWI KARINA BR GINTING");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320, 320, -240, 240);

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);  // Menambahkan fungsi keyboard

    glutMainLoop();
    return 0;
}