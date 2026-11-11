#include <bits/stdc++.h>
using namespace std;
string rc,rz,fc,fz;
int rm,fm,y=0;
int cnt;


int main(){
    cin>>rc>>rz>>fc>>fz;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    if(rc==fc){
        cout<<1;
        cnt++;
    }else{
        cout<<0;
    }

    if(rz[1]==fz[1] && rz[0]==fz[0] && cnt==1){
        cout<<1;
        cnt++;
    }else{
        cout<<0;
    }

    if(rz[2]=='A' || rz[2]=='B' || rz[2]=='C'){
        rm=0;
    }else{
        rm=1;
    }
    if(fz[2]=='A' || fz[2]=='B' || fz[2]=='C'){
        fm=0;
    }else{
        fm=1;
    }

    if(rm==fm && cnt==2){
        cout<<1;
        cnt++;
    }else{
        cout<<0;
    }

    if(abs(rz[2]-fz[2])==1 && rm==fm) y=1;
    if(abs(rz[2]-fz[2])==2 && rm!=fm) y=1;
    if(y==1 && cnt==3){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}