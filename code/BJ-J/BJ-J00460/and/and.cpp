#include<bits/stdc++.h>
using namespace std;
int n,ans,a[200001],m,maxn;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    if (m==1)
    {
        for (int i=1;i<=n;++i)
        {
            maxn=max(maxn,a[i]);
        }
    }
    if (m==2)
    {
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=n;++j)
            {
                if (j!=i)
                {
                    maxn=max(maxn,a[i]&a[j]);
                }
            }
        }
    }
    if (m==n)
    {
        maxn=a[1];
        for (int i=2;i<=n;++i)
        {
            maxn&=a[i];
        }
    }
    if (m==n-1)
    {

        for (int i=1;i<=n;++i)
        {
            if (i==1)
            {
                maxn=a[2];
            }
            else
            {
                maxn=a[i-1];
            }
            for (int j=1;j<=n;++i)
            {
                if (i!=j)
                {
                    maxn&=a[j];
                }
            }
        }
    }
    cout<<maxn;
    return 0;
}