#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll a[N],s[N],h[N];
ll n,m;
ll phi(ll i,ll b)
{
    ll c=h[i]-h[b]-(i-b)*s[b];
    return c;
}
ll ef(ll l,ll r)
{
    ll ans=l-1;
    ll L=l;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(phi(mid,L-1)<=m)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<ll>());
    s[1]=0;
    for(int i=2;i<=n;i++)
    {
        s[i]=s[i-1]+a[i-1]-a[i];
        h[i]=h[i-1]+s[i];
    }
    ll ans=1;
    for(int i=1;i<n;i++)
    {
        ll sum=ef(i+1,n);
        ans=max(ans,sum-i+1);
    }
    cout<<ans<<endl;
    return 0;
}
