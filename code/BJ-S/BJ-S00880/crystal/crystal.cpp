#include <bits/stdc++.h>
using namespace std;
const long long N=500005;
long long a[N],s[N];
long long n,m;
bool check(long long val)
{
    long long sum=1e18;
    for(long long r=val;r<=n;r++)
    {
        long long x=(val-1)*a[r]-s[r-1]+s[r-val];
        sum=min(sum,x);
    }
    return sum<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    long long l=1,r=n,ans=1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
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
    cout<<ans;
    return 0;
}
