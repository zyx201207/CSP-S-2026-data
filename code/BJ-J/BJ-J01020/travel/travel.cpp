#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a, b;
    string c, s;
    cin >> a >> c >> b >> s;
    int e = c[0] - '0' *10 + (c[1] - '0');
    int f = s[0] - '0' *10 + (s[1] - '0');
    if(a == b){
        cout << "1";
        if(e == f){
            cout << "1";
            if(c[2] == 'E'|| c[2] =='D'||c[2] == 'C'&&c[2] =='B'|| c[2]== 'A'){
                cout << "1";
                if(s[2]== 'A'|| s[2]=='B'||s[2]== 'C'&&s[2]=='D'|| s[2]== 'E'){
                    cout << "1";
                }
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}