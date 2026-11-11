#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char s1a=(s1[0]-'0');
    char s1b=(s1[1]-'0');
    char s2a=(s2[0]-'0');
    char s2b=(s2[1]-'0');
    char s1c=s1[2];
    char s2c=s2[2];
    if(c1==c2&&c1==2)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1a==s2a&&s1b==s2b)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s1c<='C'&&s2c<='C')
    {
        cout<<1;
    }
    else if(s1c>='D'&&s2c>='D')
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(s1c=='A'&&s2c=='B')
    {
        cout<<1;
    }
    else if(s2c=='A'&&s1c=='B')
    {
        cout<<1;
    }
    else if(s1c=='B'&&s2c=='C')
    {
        cout<<1;
    }
    else if(s2c=='B'&&s1c=='C')
    {
        cout<<1;
    }
    else if(s1c=='D'&&s2c=='F')
    {
        cout<<1;
    }
    else if(s2c=='D'&&s1c=='F')
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
