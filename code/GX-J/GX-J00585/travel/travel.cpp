#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    char a[10],b[10],c[10],d[10],ans[4];
    int n,i;
    cin>>a>>b>>c>>d;
    for(i=0; i<4; ++i)
    {
        ans[i]='0';
    }
    for(i=0; i<2; ++i)
    {
        if(a[0]==c[0] && a[1]==c[1])
        {
            ans[0]='1';
            break;
        }
        else
        {
            ans[0]='0';
        }
    }
    if(ans[0]=='1')
    {
        for(i=0; i<3; ++i)
        {
            if(b[0]==d[0] && b[1]==d[1])
            {
                ans[1]='1';
                break;
            }
            else
            {
                ans[1]='0';
            }
        }
    }
    for(i=0; i<3; ++i)
    {
        if(ans[1]=='1')
        {
            if(b[2]=='A' || b[2]=='B' || b[2]=='C')
            {
                if(d[2]=='A' || d[2]=='B' || d[2]=='C')
                {
                    ans[2]='1';
                }
                break;
            }
            else if(b[2]=='D' || b[2]=='F')
            {
                if(d[2]=='D' || d[2]=='F')
                {
                    ans[2]='1';
                    break;
                }
            }
            else
            {
                ans[2]='0';
            }
        }

    }
    if(ans[2]=='1')
    {
        if(b[2]=='A' && d[2]=='B')
        {
            ans[3]='1';
        }
        else if(b[2]=='B' && d[2]=='A')
        {
            ans[3]='1';
        }
        else if(b[2]=='B' && d[2]=='C')
        {
            ans[3]='1';
        }
        else if(b[2]=='C' && d[2]=='B')
        {
            ans[3]='1';
        }
        else if(b[2]=='D' && d[2]=='F')
        {
            ans[3]='1';
        }
        else if(b[2]=='F' && d[2]=='D')
        {
            ans[3]='1';
        }
        else
        {
            ans[3]='0';
        }
    }
    else
    {
        ans[3]='0';
    }
    for(i=0; i<4; ++i)
    {
        cout<<ans[i];
    }
    return 0;
}
