#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005];
bool check(long long x)
{
    long long y=0;
    for(long long i=1;i<=x;i++)
    {
        y+=a[x]-a[i];
    }
    long long minn=y;
    for(long long i=2;i+x<=n;i++)
    {
        y-=a[i-1];
        y+=a[i+x];
        minn=min(minn, y);
    }
    return m>=minn;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(long long i=1;i<=n;i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    long long l=1, r=n, ans;
    while(l<r)
    {
        long long mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    printf("%lld", ans);
    return 0;
}