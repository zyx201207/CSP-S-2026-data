#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a,b,x,y;
bool p=true;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<=1;i++)
    {
        if(s1[i]!=s2[i])
        {
            p=false;
            break;
        }
    }
    if(p==false)
    {
        cout<<"1000";
        return 0;
    }
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    {
        if(s2[2]=='D'||s2[2]=='F')
        {
            cout<<"1100";
            return 0;
        }
    }
    else if(s1[2]=='D'||s1[2]=='F')
    {
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
        {
            cout<<"1100";
            return 0;
        }
    }
    x=s1[2]-'0';
    y=s2[2]-'0';
    if(abs(x-y)==1)
    {
        cout<<"1111";
    }
    else
    {
        cout<<"1110";
    }
    return 0;
}
