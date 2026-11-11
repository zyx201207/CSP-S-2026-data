#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+10;
ll a[N],sum[N];

ll check(ll x,ll m,ll rr)
{
	ll l=1,r=rr,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1ll;
		ll tmp=x*(rr-mid+1ll)-sum[rr]+sum[mid-1];
		if(tmp<=m) r=mid-1,ans=(rr-mid+1ll);
		else l=mid+1;
	}
	return ans;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];//,cout<<a[i]<<" ";
	ll ans=1;
	for(ll i=1;i<=n;i++) ans=max(ans,check(a[i],m,i));
	cout<<ans;
	return 0;
}
