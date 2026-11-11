#include<bits/stdc++.h>
using namespace std;
string c1 , s1 , c2 , s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    string s10 = s1[0]+s1[1] , s11 = s1[2] , s20 = s2[0]+s2[1] , s21 = s2[2];
    if(c1 == c2){
        cout << "1";
        if(s10 == s20){
            cout << "1";
            if(s11=='A' && s21=='B' || s11=='A' && s21=='C' ||s11=='B' && s21=='A' ||s11=='B' && s21=='C' ||s11=='C' && s21=='A' || s11=='C' && s21=='B' || s11=='D' && s21=='F' || s11=='F' && s21=='D'){
                cout << "1";
                if(s11=='A' && s21=='B' || s11=='B' && s21=='A' || s11=='B' && s21=='C' || s11=='C' && s21=='B' || s11=='D' && s21=='F' || s11=='F' && s21=='D'){
                    cout << "1";
                }else{
                    cout << "0";
                    return 0;
                }
            }else{
                cout << "00";
                return 0;
            }
        }else{
            cout << "000";
            return 0;
        }
    }else{
        cout <<"0000";
        return 0;
    }
    return 0;
}

