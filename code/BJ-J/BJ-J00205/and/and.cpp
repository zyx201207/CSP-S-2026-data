#include <bits/stdc++.h>
using namespace std;

int n,m;
int a,b=0,c,s,d;

int main()
{
    freopen ("and.in","r",stdin);
    freopen ("and.out","r",stdout);
    cin>>n>>m;
    if(m==1)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a>b)
            {
                b=a;
            }
        }
        cout<<b;
    }
    else if(m==2)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a;
            c=a&b;
            if(c>s)
            {
                s=c;
            }
            b=a;
        }
        cout<<c;
    }
     else
    {
        for(int i=0;i<n;i++)
        {
            cin>>a;
            d=a&b&c;
            if(d>s)
            {
                s=d;
            }
            c=b;
            b=a;
        }
        cout<<c;
    }

    return 0;
}
