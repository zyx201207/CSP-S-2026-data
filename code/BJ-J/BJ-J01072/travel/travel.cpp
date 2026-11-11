#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a=0,b=0,c=0,d=0;
bool check(char x,char y){
    if(x==y) return 1;
    if(x=='D'&&y=='F') return 1;
    if(x=='F'&&y=='D') return 1;
    if((x=='A'&&y=='B')||(x=='B'&&y=='A')) return 1;
    if((x=='A'&&y=='C')||(x=='C'&&y=='A')) return 1;
    if((x=='C'&&y=='B')||(x=='B'&&y=='C')) return 1;
    return 0;
}
bool check2(char x,char y){
    if(x=='D'&&y=='F') return 1;
    if(x=='F'&&y=='D') return 1;
    if((x=='A'&&y=='B')||(x=='B'&&y=='A')) return 1;
    if((x=='C'&&y=='B')||(x=='B'&&y=='C')) return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
  
    cin>>c1>>s1>>c2>>s2;
    a=(c1==c2);
    b=(a&&(s1[0]==s2[0]&&s1[1]==s2[1]));
    c=(b&&check(s1[2],s2[2]));
    d=(c&&check2(s1[2],s2[2]));
    cout<<a<<b<<c<<d<<endl;
    return 0;
}