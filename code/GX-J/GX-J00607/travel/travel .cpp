#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[2],s1[3],c2[2],s2[3],x[3]={'A','B','C'},y[2]={'D','F'};
    int i,m=0,n=0;
    for(i=0;i<2;++i)
    {
        cin>>c1[i];
    }
    for(i=0;i<3;++i)
    {
        cin>>s1[i];
    }
    for(i=0;i<2;++i)
    {
        cin>>c2[i];
    }
    for(i=0;i<3;++i)
    {
        cin>>s2[i];
    }
    if(c1[0]==c2[0] && c1[1]==c2[1])
    {
        cout<<"1";
    }
    else
    {
        cout<<"0"<<"0"<<"0"<<"0";
        return 0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1])
    {
        cout<<"1";
    }
    else
    {
        cout<<"0"<<"0"<<"0";
        return 0;
    }
    for(i=0;i<3;++i)
    {
        if(s1[2]==x[i] || s2[2]==x[i])
        {
           m++;
        }
        if(s1[2]==y[i] || s2[2]==y[i])
        {
            n++;
        }
    }
    if(n==2)
    {
        cout<<"1"<<"1";
        return 0;
    }
    else if(m==2)
    {
        cout<<"1";
        if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1)
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
    else
    {
        cout<<"0"<<"0";
    }
    return 0;
}

