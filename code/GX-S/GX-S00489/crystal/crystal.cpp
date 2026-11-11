#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5;
ll n,a[N+5],m,sum[N+5];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    ll ans=1;
    for(ll i=1,l=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        while((i-l+1)*a[i]-(sum[i]-sum[l-1])>m) l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
