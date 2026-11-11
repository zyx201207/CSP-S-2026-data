#include<iostream>
#include<cstdio>
using namespace std;

string c1,s1,c2,s2;
long long f1,f2,f3,f4,f5;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) f1=1;
    if((s1[0]==s2[0]&&s1[1]==s2[1])&&f1==1) f2=1;
    if(((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D'))&&f2==1) f3=1;
    long long p1=(s1[0]-'0')*10+s1[1]-'0';
    long long p2=(s1[0]-'0')*10+s1[1]-'0';
    if(f1==1&&f2==1&&f3==1&&((abs(p1-p2)==1&&s1[2]==s2[2])||(p1==p2&&abs(s1[2]-s2[2])==1))) f4=1;
    cout<<f1<<f2<<f3<<f4;
}
