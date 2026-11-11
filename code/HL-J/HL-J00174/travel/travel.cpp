#include <bits/stdc++.h>
using namespace std;
string co,so,ct,st;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> co >> so >> ct >> st;
    if(co!=so){
        cout << "0000";
    }
    else if(co==so){
        cout << "1";
        if(ct[0]+ct[1]==st[0]+st[1]){
            cout << "1";
            if((ct[2]=='A'&&st[2]=='B')||(ct[2]=='A'&&st[2]=='C')||(ct[2]=='B'&&st[2|=='A')||
            (ct[2]=='B'&&st[2]=='C')||(ct[2]=='C'&&st[2]=='A')||(ct[2]=='C'&&st[2]=='B')){
                    cout << "11";
                }
            }
        }
    return 0;
}
