#include<bits/stdc++.h>
using namespace std;
string ac,as,bc,bs;
bool dp,ep,sp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ac>>as>>bc>>bs;
    if(ac==bc){
        cout<<1;
        dp=true;
    }
    else cout<<0;

    if(as[0]==bs[0]&&as[1]==bs[1]&&dp==true){
        cout<<1;
        ep=true;
    }
    else cout<<0;

    if(ep==true&&( (as[2]>='A'&&as[2]<='C') && (bs[2]>='A'&&bs[2]<='C') || (as[2]>='D'&&as[2]<='E') && (bs[2]>='D'&&bs[2]<='F') )){
        cout<<1;
        sp=true;
    }
    else cout<<0;

    if((as[2]=='A'&&bs[2]=='B' || as[2]=='B'&&bs[2]=='A' || as[2]=='B'&&bs[2]=='C' || as[2]=='C'&&bs[2]=='B' || as[2]=='D'&&bs[2]=='F' || as[2]=='F'&bs[2]=='D')&&sp==true)
        cout<<1;
    else cout<<0;
    return 0;
}

