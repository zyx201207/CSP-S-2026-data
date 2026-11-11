#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool check(long long h)
{
    long long l = 1,ans=0;
    for(long long i = 1;i<=h;i++) ans += a[i];
    
    if(h*a[h]-ans<=m) return true;
    for(long long i = h+1;i<=n;i++)
    {
        ans += a[i];
        ans-=a[l];
        if(h*a[i]-ans<=m) return true;
        l++;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i = 1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long l = 1,r=n,ans=1;
    while(l<r)
    {
        long long mid = (l+r)/2;
        if(check(mid))
        {
            l = mid+1;
            ans = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout<<ans;
    return 0;
}