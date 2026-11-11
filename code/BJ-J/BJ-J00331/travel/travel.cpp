#include<bits/stdc++.h>
using namespace std;
struct ticket
{
    string c;
    string s;
};
ticket a,b;
bool r[4]={1,1,1,1};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a.c>>a.s>>b.c>>b.s;
    for(int i=0;i<=1;i=i+1)
    {
        if(a.c[i]!=b.c[i])
        {
            r[0]=0;
        }
    }
    if(r[0])
    {
        for(int i=0;i<=1;i=i+1)
        {
            if(a.s[i]!=b.s[i])
            {
                r[1]=0;
            }
        }
    }
    else
    {
        r[1]=r[2]=r[3]=0;
    }
    if(r[1])
    {
        if(a.s[2]=='D'&&b.s[2]!='F')
        {
            r[2]=0;
        }
        else if(a.s[2]=='F'&&b.s[2]!='D')
        {
            r[2]=0;
        }
        else
        {
            if(b.s[2]=='D'||b.s[2]=='F')
            {
                r[2]=0;
            }
        }
    }
    else
    {
        r[2]=r[3]=0;
    }
    if(r[2])
    {
        if(a.s[2]!=b.s[2]+1)
        {
            if(a.s[2]!='F')
            {
                if(a.s[2]+1!=b.s[2])
                {
                    if(b.s[2]!='F')
                    {
                        r[3]=0;
                    }
                    else if(b.s[2]!='D')
                    {
                        r[3]=0;
                    }
                }
                if(b.s[2]=='D')
                {
                    r[3]=0;
                }
            }
            else if(b.s[2]!='D')
            {
                r[3]=0;
            }
            if(a.s[2]=='D')
            {
                r[3]=0;
            }
        }
    }
    else
    {
        r[3]=0;
    }
    cout<<r[0]<<r[1]<<r[2]<<r[3];
    return 0;
}