#include<bits/stdc++.h>
using namespace std;
long long rc,xc;
string rz,xz;
bool cx,cp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rz>>xc>>xz;
    if(rc==xc){
        cout<<1;
        cx=1;
    }else{
        cout<<0;
    }
    if(cx==1){
        if(rz[0]==xz[0]&&rz[1]==xz[1]){
            cout<<1;
            cp=1;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    if(cp==1&&cx==1){
        if(((rz[2]=='F'||rz[2]=='D')&&(xz[2]=='F'||xz[2]=='D'))||((rz[2]=='A'||rz[2]=='B'||rz[2]=='C')&&(xz[2]=='A'||xz[2]=='B'||xz[2]=='C'))){
           cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    char x,y;
    x=xz[2];
    y=rz[2];
    if(((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))&&cp==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
