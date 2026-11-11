#include<bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
char a[5], b[5];
bool flag1, flag2, flag;
int main(){
string s1, s2, s3, s4;
char a[5], b[5];
bool flag1 = false, flag2 = false, flag = false;
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    a[0] = 'A';
    a[1] = 'B';
    a[2] = 'C';
    b[0] = 'D';
    b[1] = 'F';
    cin >> s1 >> s2 >> s3 >> s4;
    if(s1 == s3){ cout << '1';
        if(s2[0] == s4[0] && s2[1] == s4[1]){
            cout << '1';
            for(int i = 0; i < 3; i++){
                if(a[i] == s2[2]) flag1 = true;
                if(a[i] == s4[2]) flag2 = true;
            }
                if(flag1 == flag2){ 
                    cout << '1';
                    for(int i = 0; i < 3; i++){
                        if(flag1){
                            if(s2[2] == 'A' && s4[2] == 'C' || s4[2] == 'A' && s2[2] == 'C') cout << '0';
                            else cout << '1';
                        }
                    }
                }
                else cout << '0';
        }
    else cout << "00";
    }
    else cout << "0000";
    return 0;
}