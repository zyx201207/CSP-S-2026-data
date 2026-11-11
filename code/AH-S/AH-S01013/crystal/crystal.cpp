#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=5e5+10;

ll a[N];
ll f[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ll n,m;cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=n,res=m;
    for(ll i=n;i>=1;i--)
    {
        if(i<n) res+=(a[i+1]-a[i])*(f[i+1]-1);
        while(l>=1&&res>=a[i]-a[l])
        {
            res-=a[i]-a[l];
            l--;
        }
        f[i]=i-l;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans;
    return 0;
}
