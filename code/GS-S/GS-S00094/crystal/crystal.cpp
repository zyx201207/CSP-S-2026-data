#include <bits/stdc++.h>

using namespace std;

long long n,m,a[500005],s[500005];

bool check(long long mid)
{
    long long cur=0;
    for(long long i=1; i<=mid; i++) cur+=s[i];
    long long need=cur-mid*s[mid];
    if(need<=m) return true;
    for(long long i=2; i+mid-1<=n; i++)
    {
        cur-=s[i-1];
        cur+=s[i+mid-1];
        long long need=cur-mid*s[i+mid-1];
        if(need<=m) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(long long i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(long long i=1; i<=n; i++) s[i]=a[n]-a[i];
    long long l=1,r=n,ans=-1;
    while(l<=r)
    {
        long long mid=l+(r-l)/2;
        if(check(mid))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << ans;
    return 0;
}
