#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1[3],c2,s2[3];
    cin>>c1>>s1[3]>>c2>>s2[3];
    int a=0,b=0,c=0,d=0;
    if(c1==c2)
    {
        a=1;
    }
    else
    {
        a=0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        b=1;
    }
    else
    {
        b=0;
    }
    if(s1[2]=='A'||'B'||'C'&&s2[2]=='A'||'B'||'C')
    {
        c=1;
    }
    else if(s1[2]=='E'||'F'&&s2[2]=='E'||'F')
    {
        c=0;
    }
    for(int i=0;i<3;i++)
    {
        if(s1[i]==s2[i+1])
        {
            d=1;
        }
        else
        {
            d=0;
        }
    }
    cout <<a<<b<<c<<d;
    return 0;
}
