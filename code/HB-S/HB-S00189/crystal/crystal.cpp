#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],n,m,maxx=-1;
bool check(long long x,long long k)
{
    if(sum[k]-sum[x]-1LL*(x-1)*(a[k]-a[x])<=m) return 1;
    return 0;
}
long long erfen(long long l,long long r,long long k)
{
    long long ans;
    while(l<=r)
    {
        long long mid=(l+r)>>1;
        if(check(mid,k))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+1LL*(i-1)*(a[i]-a[i-1]);
    }
    for(int i=1;i<=n;i++)
    {
        maxx=max(maxx,i+1-erfen(1,i-1,i));
    }
    cout<<maxx;
    return 0;
}
