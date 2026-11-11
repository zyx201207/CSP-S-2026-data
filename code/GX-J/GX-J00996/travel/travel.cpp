#include<bits/stdc++.h>
using namespace std;
long long a,b,c=1;
string s1;
string s2;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>s1>>b>>s2;
if(a==b)
{
    cout<<1;//                       no.1
}
else
{
    cout<<0;
    cout<<0;
    cout<<0;
    cout<<0;
    return 0;
}
if(s1[0]==s2[0]&&s1[1]==s2[1])
{
    cout<<1;//                          no.2
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
    {
        cout<<1;//                          no.3
        if(s1[2]=='A'||s1[2]=='B'&&s2[2]=='B'||s2[2]=='A')
        {
            cout<<s1[2];//                                    no.4
            return 0;
        }
        else if(s1[2]=='C'||s1[2]=='B'&&s2[2]=='B'||s2[2]=='C')
        {
            cout<<1;//                           no.4
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F')
    {
        cout<<11;
        return 0;
    }
    else
    {
        cout<<0;
        cout<<0;
        return 0;
    }
}
else
{
    cout<<0;
    cout<<0;
    cout<<0;
}
return 0;
}
