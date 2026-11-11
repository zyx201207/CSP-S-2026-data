#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	ll n,d;
	cin>>n>>d;
	vector<ll> a(n+1),r(n+1,0);
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		r[i]=max(r[i-1],i);
		while(r[i]<n&&a[r[i]+1]-a[i]<=d) r[i]++;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		if(r[i]-i<2||r[r[i]]==r[i]) continue;
		ans+=r[r[i]-1]-r[r[i]-2];
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll cas,T;
	cin>>cas>>T;
	while(T--) solve();
}
