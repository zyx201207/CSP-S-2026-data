#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],maxn;
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        {
            f=1;
        }
    }
    if(f==0)
    {
        long long h=0;
        for(int i=n;i>=1;i--)
        {
            if(i*i-i*(i+1)/2<=m)
            {
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        long long ans=0,s=m;
        for(int j=1;j<=n;j++)
        {
            if(a[j]<a[i] && s-a[i]+a[j]>=0)
            {
                s=s-a[i]+a[j];
                ans++;
            }
            else if(a[j]==a[i])
            {
                ans++;
            }
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}
