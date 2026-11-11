#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string p,s;
    string c1,s1.c2.s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0000;
        return 0;
    }
    p=s1[0]+s1[1];
    s=s2[0]+s2[1];
    if(p==s)
    {
        cout<<1;
    }
    else
    {
        cout<<000;
        return 0;
    }
    if(s1[2]=='D'&& s2[2]=='F')
    {
        cout<<11;
        return 0;
    }
    else if(s1[2]=='C'&& s2=='B'||s1[2]=='B'&& s2=='C'||s1[2]=='B'&& s2=='A'||s1[2]=='A'&& s2=='B')
    {
        cout<<11;
        return 0;
    }
    else if(s1[2]=='A'&& s2[2]=='C' || s1[2]=='C'&& s2[2]=='A')
    {
        cout<<10;
        return 0;
    }
    else
    {
        cout<<00;
        return 0;
    }
}
