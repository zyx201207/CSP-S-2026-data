#include<bits/stdc++.h>
using namespace std;
int ti(string s){
    return (s[0]-'0')*10+(s[1]-'0');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    int a,b,d,e;
    char c,f;
    a=ti(a1);
    b=ti(b1);
    d=ti(a2);
    e=ti(b2);
    c=b1[2];
    f=b2[2];
    bool k1=0,k2=0,k3=0,k4=0;
    if(a==d)k1=1;
    if(k1&&b==e)k2=1;
    if(k2&&((c>='A'&&c<='C'&&f>='A'&&f<='C')||(c>='D'&&c<='F'&&f>='D'&&f<='F')))k3=1;
    if(k3&&((c=='A'&&f=='B')||(c=='B'&&f=='C')||(c=='D'&&f=='F')||(f=='A'&&c=='B')||(f=='B'&&c=='C')||(f=='D'&&c=='F')))k4=1;
    cout<<k1<<k2<<k3<<k4<<endl;


    return 0;
}
