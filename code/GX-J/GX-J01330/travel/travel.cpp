#include <bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rz>>xc>>xz;
    if(rc[0]==xc[0]&&rc[1]==xc[1]){
        cout<<"1";
        if(rz[0]==xz[0]&&rz[1]==xz[1]){
            cout<<"1";
            if(rz[2]<='C'&&xz[2]<='C' || rz[2]>'C'&&xz[2]>'C'){
                cout<<"1";
                if(rz[2]=='D'||rz[2]=='F'){
                    cout<<"1";
                }else if(rz[2]+1==xz[2] || rz[2]-1==xz[2]){
                    cout<<"1";
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
