#include <bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
       cout << "1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout << "1";
            char a=s1[2];
            char b=s2[2];
            if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
                cout << "1";
                if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
                    cout << "1";
                }
                else{
                    cout << "0";
                }
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
