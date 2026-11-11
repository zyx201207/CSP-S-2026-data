#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+7;
ll c,n,m,d,Q;
ll to[N];
vector<pair<ll,ll>>edge[N];
ll dis[N];
bool vis[N];
ll f[1007][1007];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++)
		cin>>to[i];
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		while(k--)
		{
			ll zt,v;
			cin>>zt>>v;
			edge[zt+n].push_back({i,v});
			edge[i].push_back({zt+n,v});
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
			f[i][j]=1e18;
		f[i][i]=0;
	}
	for(ll i=1;i<=n;i++)
	{
		for(auto&A1:edge[i])
		{
			ll v1=A1.first;
			ll l1=A1.second;
			for(auto&A2:edge[v1])
			{
				ll v2=A2.first;
				ll l2=A2.second;
				f[i][v2]=min(f[i][v2],l1+l2);
			}
		}
	}
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	while(Q--)
	{
		ll x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(auto A1:edge[x+n])
		{
			ll v1=A1.first;
			ll l1=A1.second;
			for(auto A2:edge[y+n])
			{
				ll v2=A2.first;
				ll l2=A2.second;
				ans=min(ans,f[v1][v2]+to[x]+to[y]+l1+l2);
			}
		}
		cout<<ans<<'\n';
	}
}
