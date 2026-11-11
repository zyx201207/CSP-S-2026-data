#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    char a,b,c,d;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)a='1';
    else a='0';
    if(s1[1]==s2[1]&&s1[0]==s2[0]&&a=='1')b='1';
    else b='0';
    if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&b=='1')c='1';
    else c='0';
    int x=s1[2]-'A',y=s2[2]-'A';
    if((x==y+1||y==x+1)&&c=='1')d='1';
    else d='0';
    cout<<a<<b<<c<<d;
}
