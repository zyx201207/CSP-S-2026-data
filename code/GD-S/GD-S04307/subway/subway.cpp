#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define il inline
using namespace std;
const int maxn=5e5+10;
int n,m,d,q;
int a[maxn],dis[510][510];
vector<pii> g[maxn];
signed main()
{
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _;cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			g[x].pb({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int l=g[i].size();
		for(int j=0;j<l;j++) for(int k=j+1;k<l;k++)
		{
			int u=g[i][j].fi,v=g[i][k].fi;
			dis[u][v]=dis[v][u]=min(dis[u][v],g[i][j].se+g[i][k].se);
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int u,v,ans=1e18;
		cin>>u>>v;
		for(int i=0;i<g[u].size();i++) for(int j=0;j<g[v].size();j++)
			ans=min(ans,dis[g[u][i].fi][g[v][j].fi]+g[u][i].se+g[v][j].se);
		cout<<ans+a[u]+a[v]<<endl;
	}
}
