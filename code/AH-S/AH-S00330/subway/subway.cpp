#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e2+5,M=5e5+5;
ll cas,n,m,d,q,w[M],g[N][N],dis[N][N];
vector<pair<ll,ll>> id[M];
void build()
{
	memset(g,0x3f,sizeof(g));
	for(ll i=1;i<=n;i++) g[i][i]=0;
	for(ll i=1;i<=m;i++)
	{
		for(auto tu:id[i]) for(auto tv:id[i])
		{
			ll u=tu.first,wu=tu.second;
			ll v=tv.first,wv=tv.second;
			if(u==v) continue;
			g[u][v]=min(g[u][v],wu+wv);
		}
	}
}
void floyd()
{
	for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) dis[i][j]=g[i][j];
	for(ll u=1;u<=n;u++) for(ll i=1;i<=n;i++) for(ll v=1;v<=n;v++)
		dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cas>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		while(k--)
		{
			ll a,t;
			cin>>a>>t;
			id[a].push_back({i,t});
		}
	}
	build(),floyd();
	while(q--)
	{
		ll u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(auto tu:id[u]) for(auto tv:id[v])
		{
			ll lu=tu.first,wu=tu.second+w[u];
			ll lv=tv.first,wv=tv.second+w[v];
			ans=min(ans,wu+wv+dis[lu][lv]);
		}
		cout<<ans<<"\n";
	}
}
