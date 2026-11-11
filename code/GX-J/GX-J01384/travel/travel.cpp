#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char f1=s1[2],f2=s2[2];
    int a=0,b=0,c=0,d=0;
    if(c1==c2) a=1;
    if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1]) b=1;
    if(a==1&&b==1){
        if(f1>='A'&&f1<='C'&&f2>='A'&&f2<='C') c=1;
        if(f1>='D'&&f1<='F'&&f2>='D'&&f2<='F') c=1;
    }
    if(a==1&&b==1){
        if(f1=='A'&&f2=='B') d=1;
        if(f1=='B'&&f2=='A') d=1;
        if(f1=='B'&&f2=='C') d=1;
        if(f1=='C'&&f2=='B') d=1;
        if(f1=='D'&&f2=='F') d=1;
        if(f1=='F'&&f2=='D') d=1;
    }
    cout<<a<<" "<<b<<" "<<c<<" "<<d;
    return 0;
}
