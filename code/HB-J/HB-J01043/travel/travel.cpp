#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,r;
    int a,b,c,d;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++){
        if(c1[i]==c2[i]) a=1;
        else a=0;
    }
    for(int i=0;i<=1;i++){
        if(s1[i]==s2[i]) b=1;
        else b=0;
    }
    if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')) c=1;
    else if((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D')) c=1;
    else c=0;
    if(s1[2]==s2[2]+1||s1[2]==s2[2]-1) d=1;
    else d=0;
    if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')) d=0;
    if(a==0){
        b=0;
        c=0;
        d=0;
    }
    if(b==0){
        c=0;
        d=0;
    }
    if(c==0){
        d=0;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
