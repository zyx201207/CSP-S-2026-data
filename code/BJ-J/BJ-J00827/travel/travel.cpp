#include<bits/stdc++.h>
using namespace std;
int a(char c)
{
    if (c=='A')
    {
        return 1;
    }
    if (c=='B')
    {
        return 2;
    }
    if (c=='C')
    {
        return 3;
    }
    if (c=='D')
    {
        return 5;
    }
    if (c=='F')
    {
        return 6;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    s=s1+' '+s2+' '+s3+' '+s4;
    if (s[0]==s[7] && s[1]==s[8])
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if (s[3]==s[10] && s[4]==s[11])
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if ((a(s[5])>4 && a(s[12])>4) || (a(s[5])<4 && a(s[12])<4))
    {
        cout<<"1";
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if (abs(a(s[5])-a(s[12]))==1)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
