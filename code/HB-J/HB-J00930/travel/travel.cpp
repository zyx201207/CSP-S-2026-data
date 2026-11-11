#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char r[2],rr[3],x[2],xx[3];
    for(int i=0;i<2;i++){
        cin>>r[i];
    }
    for(int i=0;i<3;i++){
        cin>>rr[i];
    }
    for(int i=0;i<2;i++){
        cin>>x[i];
    }
    for(int i=0;i<3;i++){
        cin>>xx[i];
    }
    if(int(r[0])==int(x[0]) and int(r[1])==int(x[1])){
        cout<<1;
        if(int(rr[0])==int(xx[0]) and int(rr[1])==int(xx[1])){
            cout<<1;
            if(((xx[2]=='A' or xx[2]=='B' or xx[2]=='C') and (rr[2]=='A' or rr[2]=='B' or rr[2]=='C')) or ((xx[2]=='D' or xx[2]=='F') and (rr[2]=='D' or rr[2]=='F'))){
                cout<<1;
                if(((xx[2]=='A' or xx[2]=='C') and rr[2]=='B') or ((rr[2]=='A' or rr[2]=='C') and xx[2]=='B') or (xx[2]=='D' or rr[2]=='F') or (xx[2]=='F' or rr[2]=='D')){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
