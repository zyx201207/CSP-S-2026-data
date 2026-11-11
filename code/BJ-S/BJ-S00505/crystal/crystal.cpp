#include<bits/stdc++.h>
const long long N=5e5+5;
long long n,m,a[N],sum[N],ans;
long long getsum(long long l,long long r)
{
    return sum[r]-sum[l-1];
}
long long check(long long x,long long i)
{
    return (a[i]*(i-x+1)-getsum(x,i))<=m;
}
long long bin_srch(long long i)
{
    long long l=1,mid,r=i;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check(mid,i))
            r=mid;
        else l=mid+1;
    }
    return l;
}
int main()
{
    std::freopen("crystal.in","r",stdin);
    std::freopen("crystal.out","w",stdout);
    std::cin >> n >> m;
    for(int i=1;i<=n;++i)
        std::cin >> a[i];
    std::sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
        sum[i]=sum[i-1]+a[i];
    for(long long i=1LL;i<=n;++i)
    {
        if(m>=(a[i]*i)-sum[i])
        {
            ans=std::max(ans,i);
            continue;
        }
        //要让a[i]*(i-l+1)-getsum(l,i) <= m
        long long l=i-bin_srch(i)+1;
        ans=std::max(ans,l);
    }
    std::cout << ans;
    return 0;
}
