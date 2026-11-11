#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    string p1,p2;
    bool f1=0,f2=0,f3=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        f1=1;
    }else cout<<0;
    p1=s1.substr(0,2);
    p2=s2.substr(0,2);
    if(f1 && p1==p2){
        cout<<1;
        f2=1;
    }else{
        cout<<0;
    }
    if(f2){
        if((s1[2]=='D' && s2[2]=='E') || (s1[2]=='E' && s2[2]=='D')) cout<<1,f3=1;
        else if(s1[2]=='A' && (s2[2]=='B' || s2[2]=='C')) cout<<1,f3=1;
        else if(s1[2]=='B' && (s2[2]=='A' || s2[2]=='C')) cout<<1,f3=1;
        else if(s1[2]=='C' && (s2[2]=='A' || s2[2]=='B')) cout<<1,f3=1;
        else cout<<0;
    }else{
        cout<<0;
    }
    if(f1 && f2 && f3){
        if(s1[2]=='D' || s2[2]=='D') cout<<1;
        else if(s1[2]=='A' && s2[2]=='B') cout<<1;
        else if(s1[2]=='B' && (s2[2]=='A' || s2[2]=='C')) cout<<1;
        else if(s1[2]=='C' && s2[2]=='B') cout<<1;
        else cout<<0;
    }else{
        cout<<0;
    }
    return 0;
}
