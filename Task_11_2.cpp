#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <numeric>


std::string partFromDog (bool part,std::string text, int dogPos) {   
    return part ? text.substr(0,dogPos) : text.substr(dogPos+1,text.length()-dogPos-part);
}

bool symbolNumber (std::string text, int number) {
    if (text.length()>number) {
        return false;
    } else {
        return true;
    }
}

bool pointsCheck (std::string text) {
    if (text.length()>1) {
        for (int j=0;j<text.length()-1;j++) {
        if (text[0]=='.'
            || text[text.length()-1]=='.'
            || text[j]==text[j+1] && text [j]=='.') 
            {
                return false;
            } else {
                return true;
            }
        }
    } else {
        if (text[0]=='.') 
        {
            return false;
        } else {
            return true;
        }
    }
}


bool symbolsCheck (std::string text, bool part) {
    std::string vocabulary;
    if (part) {
        vocabulary="!#$%&'*+-/=?^_`{|}~-.";
    } else {
        vocabulary="-.";
    }
    int k,m;
    int count;
    for (k=0;k<text.length();k++) {
        count=0;
        for (m=0;m<vocabulary.length();m++) {
            if (text[k]==vocabulary[m]
                || text[k]>='A' && text[k] <= 'Z'
                || text[k]>='a' && text[k] <= 'z'
                || text[k]>='0' && text[k] <= '9') {
                count++;
            }
        }
        if (count==0) {
            return false;
            break;
        }
    }
    return true;
}
        





int main() {
    SetConsoleOutputCP(CP_UTF8);
    /* Проверка ввода данных (справочно)
    while(true)
    {
        float value; // попробуйте разные типы данных
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
            std::cout << value << '\n';
    }

    return 0;
     */
    int i;
    int countDog;
    int dogPos;
    while (true) {
        countDog=0;
        dogPos=-1;
        std::string text;
        std::cout<<"\nEnter E-mail: ";
        std::cin>>text;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::string leftText;
            std::string rightText;
            int textLength=text.length();
            for (i=0;i<textLength;i++) {
                if (text[i]==(char) 64) {
                    countDog++;
                    dogPos=i;
                }
            }
            if (countDog!=1 || dogPos<1 || dogPos>textLength-2) {
                std::cout<<"Wrong email (wrong dogs)";
            } else {
                leftText=partFromDog(1,text,dogPos);//1 - left part from dog
                rightText=partFromDog(0,text,dogPos);//0 - right part from dog
                bool rightSymbNumber=symbolNumber(leftText,64) && symbolNumber(rightText,63);
                if (!rightSymbNumber) {
                    std::cout<<"Wrong symbols amounts";
                } else {
                    bool rightPoints=pointsCheck(leftText) && pointsCheck(rightText);
                    if (!rightPoints) {
                        std::cout<<"Wrong points";
                    } else {
                        bool rightSymbols=symbolsCheck(leftText,1) && symbolsCheck(rightText,0);//1 - left part from dog; 0 - right part from dog
                        if (!rightSymbols) {
                            std::cout<<"Wrong symbols";
                        } else {
                            std::cout<<"Email is correct";
                        }
                    } 
                }
            }
        }
    }
}

    
    

    


