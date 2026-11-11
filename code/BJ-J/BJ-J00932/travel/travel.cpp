#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    int e1=int(b[1]+b[0]);
    int e2=int(d[1]+d[0]);
    char f1=b[2];
    char f2=d[2];
    if(a!=c)cout << "0000";
    else{
        cout << "1";
        if(e1==e2){
            cout << "1";
            if(((f1=='A'||f1=='B'||f1=='C')&&(f2=='A'||f2=='B'||f2=='C'))||((f1=='D'||f1=='F')&&(f2=='D'||f2=='F'))){
                cout << 1;
                if((f1=='A'&&f2=='B')||(f1=='B'&&f2=='A')||(f1=='B'&&f2=='C')||(f1=='C'&&f2=='B')||(f1=='D'&&f2=='F')||(f1=='F'&&f2=='D')){
                    cout << "1";
                }
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
}
