#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    int k1,k2,k3,k4;
    k1=k2=k3=k4=0;
    if(a==b)k1=1;
    int p1,p2;
    p1=(s1[0]-'0')*10+(s1[1]-'0');
    p2=(s2[0]-'0')*10+(s2[1]-'0');
    if(p1==p2&&k1==1)k2=1;
    if(s1[2]<'D')p1=1;
    else p1=2;
    if(s2[2]<'D')p2=1;
    else p2=2;
    if(p1==p2&&k2==1)k3=1;
    p1=s1[2]-'A';
    p2=s2[2]-'A';
    if(abs(p1-p2)==1&&k3==1)k4=1;
    cout<<k1<<k2<<k3<<k4;
    return 0;
}
