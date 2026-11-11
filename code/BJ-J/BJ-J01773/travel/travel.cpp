#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b,c,d;
char x,y;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>s1>>s2>>s3>>s4;
    a=s1[0]*10+s1[1];
    b=s3[0]*10+s3[1];
    c=s2[0]*10+s2[1];
    d=s4[0]*10+s4[1];
    x=s2[2];
    y=s4[2];
    if(a==b) f1=1;
    if(c==d&&f1==1) f2=1;
    if(x>='A'&&x<='C'&&y>='A'&&y<='C'&&f2==1&&f1==1) f3=1;
    if((x=='D'||x=='E')&&(y=='D'||y=='E')&&f2==1&&f1==1) f3=1;
    if((x+1==y||x==y+1)&&f1==1&&f2==1&&f3==1) f4=1;
    cout<<f1<<f2<<f3<<f4;
    return 0;
}