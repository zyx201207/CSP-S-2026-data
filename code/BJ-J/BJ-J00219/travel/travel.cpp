#include<bits/stdc++.h>
using namespace std;
int f1,f2,f3;
string a1,a2,b1,b2;
int deal1(char aa,char bb){
    if(f2)return 0;
    if(aa<='C'&&bb<='C')return 1;
    if(aa>='D'&&bb>='D')return 1;
    return 0;
}
int deal(char aa,char bb){
    if(f3)return 0;
    if(aa=='A'&&bb=='B')return 1;
    if(aa=='B'&&(bb=='A'||bb=='C'))return 1;
    if(aa=='C'&&bb=='B')return 1;
    if(aa=='D'&&bb=='E')return 1;
    if(aa=='E'&&bb=='D')return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)cout<<1;
    else{
        cout<<0;
        f1=1;
    }
    if(a2[0]==b2[0]&&a2[1]==b2[1]&&!f1)cout<<1;
    else{
        cout<<0;
        f2=1;
    }
    if(deal1((char)a2[2],(char)b2[2]))cout<<1;
    else{
        cout<<0;
        f3=1;
    }
    if(deal((char)a2[2],(char)b2[2]))cout<<1;
    else cout<<0;
    return 0;
}
