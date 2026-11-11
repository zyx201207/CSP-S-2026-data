#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0,d=0;
string c1,s1;
string c2,s2;
int t1=0,t2=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        a=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&a==1)
    {

        b=1;
    }
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    {

        t1=1;
    }
    else if(s1[2]=='D'||s1[2]=='F')
    {

        t1=0;
    }
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
    {

        t2=1;
    }
    else if(s2[2]=='D'||s2[2]=='F')
    {

        t2=0;
    }
    if(t1==t2&&b==1)
    {

        c=1;
    }
    else{
        c=0;
    }
    int t3=abs(s1[2]-s2[2]);
    if(t3==1&&c==1)
    {

        d=1;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
