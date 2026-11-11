#include<bits/stdc++.h>
using namespace std;
string x,y,m,n;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> x >> y >> m >> n;
    if(x==m){
        cout << '1';
        if(y[0]==n[0] && y[1]==n[1]){
            cout << '1';
            if(y[2]=='A'|| y[2]=='B' || y[2]=='C'){
                if(n[2]=='A' || n[2]=='B' || n[2]=='C'){
                    cout << 1;
                    if(y[2]==n[2]+1 || y[2]==n[2]-1){
                        cout << '1';
                    }
                    else cout << '0';
                }
                else cout << "00";
            }
            else if(y[2]=='D' || y[2]=='F'){
                if(n[2]=='D' || n[2]=='F'){
                    cout << '1';
                    if(y[2]==n[2]+1 || y[2]==n[2]-1){
                        cout << '1';
                    }
                    else cout << '0';
                }
                else cout << "00";
            }
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
