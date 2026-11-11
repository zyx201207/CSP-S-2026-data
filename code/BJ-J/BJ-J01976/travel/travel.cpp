#include<bits/stdc++.h>
using namespace std;
string rx,rz,xx,xz;
int Rz,Xz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rx>>rz>>xx>>xz;
    if(rx==xx){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    Rz=(rz[0]-'0')*10+(rz[1]-'0');
    Xz=(xz[0]-'0')*10+(xz[1]-'0');
    if(Rz==Xz){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if((rz[2]>='A'&&rz[2]<='C'&&xz[2]>='A'&&xz[2]<='C')||(rz[2]>='D'&&rz[2]<='F'&&xz[2]>='D'&&xz[2]<='F')){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }

    if((rz[2]=='A'&&xz[2]=='B')||(rz[2]=='B'&&xz[2]=='C')||(rz[2]=='B'&&xz[2]=='A')||(rz[2]=='C'&&xz[2]=='B')||(rz[2]=='D'&&xz[2]=='F')||(rz[2]=='F'&&xz[2]=='D')){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
