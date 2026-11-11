#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string sone,stwo,co,ct;
    int a,b,c,d,so,st;
    cin>>co>>sone>>ct>>stwo;
    if(sone[2]=='A'){
        so=1;
       }
    else if(sone[2]=='B'){
        so=2;
    }
    else if(sone[2]=='C'){
        so=3;
    }
    else if(sone[2]=='D'){
        so=5;
    }
    else {
        so=6;
    }
    if(stwo[2]=='A'){
        st=1;
       }
    else if(stwo[2]=='B'){
        st=2;
    }
    else if(stwo[2]=='C'){
        st=3;
    }
    else if(stwo[2]=='D'){
        st=5;
    }
    else {
        st=6;
    }
    if(so-1==st||st-1==so){
        d=1;
    }
    else{
        d=0;
    }
    if(sone[0]==stwo[0]&&sone[1]==stwo[1]){
        b=1;
        if(so<4&&st<4){
            c=1;
        }
        else if(so>4&&st>4){
            c=1;
        }
        else{
            c=0;
            d=0;
        }
    }
    else{
        b=0;
        c=0;
        d=0;
    }
    if(co==ct){
        a=1;
    }
    else{
        a=0;
        b=0;
        c=0;
        d=0;
    }
    cout<<a<<b<<c<<d;
return 0;
}

