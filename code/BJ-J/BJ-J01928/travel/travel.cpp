#include <bits/stdc++.h>
using namespace std;
string s , str , s1 , str1;
int main (){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    cin >> str >> s >> str1 >> s1;
    //cout << s[2] << " " << s1[2];
    if(str == str1){
        cout << "1";
        if(s[0] == s1[0] && s[1] == s1[1]){
            cout << "1";
            if(s[2] <= 'C' && s[2] >= 'A' && s1[2] <= 'C' && s1[2] >= 'A'){
                cout << "1";
                if(s[2] == 'A' && s1[2] == 'B'){
                    cout << "1";
                }
                else if(s[2] == 'B' && s1[2] == 'C'){
                    cout << "1";
                }
                else{
                    cout << "0";
                }
            }
            else if(s[2] == 'F' && s1[2] == 'D'){
                cout << "11";
            }
            else if(s1[2] == 'F' && s[2] == 'D'){
                cout << "11";
            }
            else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
