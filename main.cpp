#include <QCoreApplication>
#include <iostream>
#include <QDir>
#include <QDebug>

void Path();
void leer();
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int opc = 0;
    do{
        qDebug() << "\n-- MENU DE COLECCIONES --";
        qDebug() << "1. Ingresar un Path";
        qDebug() << "2. Informacion";
        qDebug() << "3. Salir";
        qDebug() << "\nIngrese su opción: ";
        std::cin >> opc;
        switch (opc) {
        case 1:
            qDebug() << "-- Listas Path --\n";
            Path();
            break;
        case 2:
            qDebug() << "-- Informacion --\n";
            leer();
        case 3:
            qDebug() << "--GRACIAS POR UTILIZARME ADIOS --";
            break;
        default:
            qDebug() << "Accion incorrecta!";
            break;
        }
    }while(opc != 3);
    return a.exec();
}
void Path(){
    QList<QDir> directorios;
    directorios.append(QDir::current());
    directorios.append(QDir::home());
    directorios.append(QDir::root());
    directorios.append(QDir::temp());

    qDebug() << "\nListar varios directorios:";
    foreach (QDir d, directorios) {
        qDebug() << d.absolutePath();
    }
}
void leer(){
    QDir directorio("C:/");
    // Obteniendo información del directorio home
    qDebug() << "\nObteniendo información de" << directorio.absolutePath() << ":";
    QFileInfoList contenido = directorio.entryInfoList();
    foreach (const QFileInfo &info, contenido) {
        qDebug() << "Nombre:" << info.fileName();
        qDebug() << "Es directorio:" << info.isDir();
        qDebug() << "Se puede escribir:" << info.isWritable();
        qDebug() << "-------------------";
    }

}
