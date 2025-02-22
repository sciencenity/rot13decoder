#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString MainWindow::rot(std::string str){
    std::string resp;
        for (size_t i = 0; i < str.size(); ++i) {
            if (isalpha(str[i])) {
                if ((tolower(str[i]) - 'a') < 13)
                    resp.append(1, str[i] + 13);
                else
                    resp.append(1, str[i] - 13);
            } else {
                resp.append(1, str[i]);
            }
        }
        return  QString::fromStdString(resp);
}
void MainWindow::on_pushButton_clicked()
{
    QString toEncode = ui->lineEdit->text();
    std::string str = toEncode.toStdString();
    ui->textBrowser->setText(rot(str));
}
