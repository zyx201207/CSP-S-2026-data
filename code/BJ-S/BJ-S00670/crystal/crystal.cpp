#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m;
bool check(long long mid)
{
    int ret=1;
    for(int i=1;i <= n;i++)
    {
        if(a[i]<=mid)
        {
            ret=i;
        }
    }
    long long sum=0;
    for(int i=1;i <= ret;i++)
    {
        sum+=mid-a[i];
    }
    return (sum<=m);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long l=-1e12,r=1e18+1e12,ans=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    int ret=1;
    for(int i=1;i <= n;i++)
    {
        if(a[i]<=ans)
        {
            ret=i;
        }
    }
    printf("%d",ret);
    return 0;
}
