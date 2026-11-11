#include<bits/stdc++.h>
using namespace std;
string ca,s,cc,ss;
int w=0,v=0;
int a=0,b=0,c=0,d=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ca>>s>>cc>>ss;
    int i=0,j=0;
    while(isdigit(s[i])){
            w=s[i]+w*10;
            i++;
    }
    while(isdigit(ss[j])){
            v=ss[j]+v*10;
            j++;
    }
    if(ca[0]==cc[0]&&ca[1]==cc[1]) a=1;
    else a=0;
    if(a!=1){
        b=0;
        c=0;
        d=0;
    }
    else if(w!=v){
        b=0;
        c=0;
        d=0;
    }
    else b=1;
    if(b!=0){
        if(s[2]=='A'){
           if(ss[2]=='B'){
                c=1;
                d=1;
           }
           else if(ss[2]=='C'){
                c=1;
                d=0;
           }
           else{
                c=0;
                d=0;
           }
        }
        if(s[2]=='B'){
           if(ss[2]=='A'||ss[2]=='C'){
                c=1;
                d=1;
           }
           else{
                c=0;
                d=0;
           }
        }
        if(s[2]=='C'){
           if(ss[2]=='B'){
                c=1;
                d=1;
           }
           else if(ss[2]=='A'){
                c=1;
                d=0;
           }
           else{
                c=0;
                d=0;
           }
        }
        if(s[2]=='D'){
           if(ss[2]=='F'){
                c=1;
                d=1;
           }
           else{
                c=0;
                d=0;
           }
        }
        if(s[2]=='F'){
           if(ss[2]=='D'){
                c=1;
                d=1;
           }
           else{
                c=0;
                d=0;
           }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
