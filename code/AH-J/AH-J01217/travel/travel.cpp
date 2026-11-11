#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int x,y;
char a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) {cout<<1;}
    else {cout<<"0000";return 0;}
    for(int i=0;i<s1.size();i++){
        if(i<=1) x=x*10+s1[i],y=y*10+s2[i];
        else a=s1[i],b=s2[i];
    }
    if(x==y) {
        cout<<1;
    }
    else {cout<<"000";return 0;}
    if(a=='D'&&b=='F'||a=='F'&&b=='D')cout<<11;
    else if(a<='C'&&b<='C'){
        cout<<1;
    }
    else {cout<<"00";return 0;}
    if(abs(a-b)==1)cout<<1;
    else cout<<0;
    return 0;
}
