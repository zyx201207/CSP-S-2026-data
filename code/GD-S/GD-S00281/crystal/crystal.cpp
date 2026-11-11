#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
const ll maxn=5e5+10;
ll n,m,a[maxn],sum[maxn];
bool check(ll x)
{
    for(int i=1;i+x-1<=n;i++)
    {
        if(x*a[i+x-1]-(sum[i+x-1]-sum[i-1])<=m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    ll l=1,r=n,ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
}
