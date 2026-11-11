#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+2;
bool side(char x1,char x2){
    bool flag1,flag2;
    if(x1<='C') flag1=true;
    else flag1=false;
    if(x2<='C') flag2=true;
    else flag2==false;
    if(flag1==flag2) return true;
    else return false;
}
bool sim(char x,char y){
    if(y<x) swap(x,y);
    if(x=='A'&&y=='B') return true;
    if(x=='B'&&y=='C') return true;
    if(x=='D'&&y=='F') return true;
}
int main(){
    string c1,s1,c2,s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        for(int i=1;i<=4;i++) cout<<0;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else{
        for(int i=1;i<=3;i++) cout<<0;
        return 0;
    }
    if(side(s1[2],s2[2])==true) cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }
    if(sim(s1[2],s2[2])==true) cout<<1;
    else cout<<0;
    return 0;
}
