#include<bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;
int tmp1, tmp2;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    tmp1 = c1[0] * 10 + c1[1];
    tmp2 = c2[0] * 10 + c2[1];
    if(tmp1 == tmp2){
        cout << 1;
        tmp1 = s1[0] * 10 + s1[1];
        tmp2 = s2[0] * 10 + s2[1];
        if(tmp1 == tmp2){
            cout << 1;
            tmp1 = s1[2] - 'A';
            tmp2 = s2[2] - 'A';
            int b1, b2;
            if(tmp1 >= 0 && tmp1 <= 2){
                b1 = 1;
            }else{
                b1 = 0;
            }
            if(tmp2 >= 0 && tmp2 <= 2){
                b2 = 1;
            }else{
                b2 = 0;
            }
            if(b1 == b2){
                cout << 1;
                if(abs(tmp1 - tmp2) == 1){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << "00";
            }
        }else{
            cout << "000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}