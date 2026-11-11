#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,x[2000005],d,f[2000005],g[2000005];
void solve()
{
	ll ans=0ll;
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>x[i],f[i]=1e18,g[i]=0ll;
	for(ll i=1;i<=n;i++)
	{
		f[i]=0ll;g[i]=1ll;
		for(ll ii=i+1ll;ii<=n;ii++)
		{
			for(ll jj=ii-1ll;jj>=i&&x[ii]-x[jj]<=d;jj--)
			{
				if(f[ii]>f[jj]+1)g[ii]=1ll,f[ii]=f[jj]+1ll;
				else if(f[ii]==f[jj]+1ll)g[ii]+=g[jj];
			}
		}
		for(ll ii=0ll;ii<=n;ii++)
		{
			if(g[ii]==2ll)ans++;
			f[ii]=1e18,g[ii]=0ll;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
