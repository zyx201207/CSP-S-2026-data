#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],maxn;
int main()
{
    freopen("and.in","r",stdin);
   /freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    maxn=max(maxn,a[i]&a[j]);

                }
            }
        }
        cout<<maxn;
    }
    else if(m==1)
    {
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout<<maxn;
    }
    else if(m==n)
    {
        maxn=a[1];
        for(int i=2;i<=n;i++) maxn&=a[i];
        cout<<maxn;
    }
    else if(m==n-1)
    {
        for(int i=2;i<=n;i++)
        {
            int z=a[1];
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    z&=a[j];
                }
            }
            maxn=max(maxn,z);
        }
        int z=a[2];
        for(int i=3;i<=n;i++)
        {
            z&=a[i];
        }
        maxn=max(maxn,z);
        cout<<maxn;
    }
    return 0;
}
