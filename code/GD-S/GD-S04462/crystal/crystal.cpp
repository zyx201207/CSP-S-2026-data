#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n,m,a[500010],sum[500010];

bool check(int len)
{
    for(int i=len;i<=n;i++)
    {
        if(a[i]*len-(sum[i]-sum[i-len])<=m)
        {
            return 1;
        }
    }
    return 0;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=0,r=1e18;
    while((r-l)>1)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    printf("%lld",l);

    return 0;
}