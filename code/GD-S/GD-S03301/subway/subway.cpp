#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define M 510
#define int long long
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
int m,n,d,q,a[N];
vector<pair<int,int> >b[N],g[M];
int dis[M];
bool vis[M];
priority_queue<pair<int,int>>Q; 
void dij(int s)
{
	for(int i=1;i<=n;i++) dis[i]=1e17,vis[i]=0;
	for(auto i:b[s])
	{
		int u=i.ff,w=i.ss;
		dis[u]=w;
		Q.push(mp(-dis[u],u));
	}
	while(!Q.empty())
	{
		pair<int,int> sta=Q.top();
		Q.pop();
		int u=sta.ss;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto now:g[u])
		{
			int v=now.ff,w=now.ss;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				Q.push(mp(-dis[v],v));
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1,s,x,y;i<=n;i++)
	{
		cin>>s;
		while(s--)
		{
			cin>>x>>y;
			b[x].push_back(mp(i,y));
		}
	}
	for(int i=1;i<=m;i++)
		for(auto j:b[i])
			for(auto k:b[i])
				if(j!=k)
				{
					int u=j.ff,v=k.ff,val=j.ss+k.ss;
					g[u].push_back(mp(v,val));
					g[v].push_back(mp(u,val));
				}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		dij(u);
		int ans=1e18;
		for(auto i:b[v])
		{
			int idx=i.ff;
			ans=min(ans,dis[idx]+i.ss); 
		}
		cout<<ans+a[u]+a[v]<<'\n';
	}
	return 0;
} 
