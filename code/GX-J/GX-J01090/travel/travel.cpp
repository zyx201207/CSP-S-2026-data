#include <bits/stdc++.h>
using namespace std;

char com1[2] = {'D','F'};
char com2[3] = {'A','B','C'};

int com(char a,char b){
    int a_t = 0;
    int b_t = 0;
    for (int i = 0;i<2;i++){
        if (a == com1[i]){
            a_t = 1;
        }
        if (b == com1[i]){
            b_t = 1;
        }
    }
    if (a_t && b_t){
        return 2;}
    for (int i = 0;i<3;i++){
        if (a == com2[i])a_t = 1;
        if (b == com2[i])b_t = 1;
    }
    if (a_t && b_t){
        return 3;}
}

int main(){
    freopen("travel1.in","r",stdin);
    freopen("travel.out","w",stdout);
    string R1,R2,X1,X2;
    cin >> R1 >> R2 >> X1 >> X2;
    int a[4] = {0,0,0,0};
    if (!R1.compare(X1)){
        a[0] = 1;
        if (R2[1] == X2[1]){
            a[1] = 1;
            if (com(R2[2],X2[2])){
                a[2] = 1;
                if (com(R2[2],X2[2]) == 2)a[3] = 1;
                else {
                    char b = R2[2];
                    char c = X2[2];
                    if(((b == 'A') || (b == 'C')) && ((c == 'A') || (c == 'C')))a[3] = 0;
                    else a[3] = 1;
                }
            }
        }

    }
    for (int i = 0;i<4;i++)cout << a[i];
}
