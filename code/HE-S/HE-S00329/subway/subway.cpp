#include <bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q,k[N],x,y;
long long w[M],a,t;

struct Edge
{
	int u,v;
	long long w;
}e[M];
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int num_edge,fa[M];
bool vis[M];
int find(int x)
{
	if (fa[x]==x) return x;
	return x=find(fa[x]);
}
void kruscal()
{
	sort(e+1,e+num_edge+1,cmp);
	for (int i=1;i<=n+m;i++) fa[i]=i;
	for (int i=1;i<=num_edge;i++)
	{
		int x=find(e[i].u);
		int y=find(e[i].v);
		if (x!=y)
		{
			fa[x]=y;
			vis[i]=true;
		}
	}
}

vector<pair<int,long long> > f[N+M];
int tot;
bool vis1[N+M];
long long ans;
bool dfs(int u,int rp)
{
	vis1[u]=true;
	if (u==rp) return true;
	for (int i=0;i<(int)f[u].size();i++)
	{
		if (vis1[f[u][i].first]) continue;
		if (dfs(f[u][i].first,rp))
		{
			ans+=f[u][i].second;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			e[++num_edge]={a,i+m,t};
		}
	}
	kruscal();
	for (int i=1;i<=num_edge;i++)
	{
		if (vis[i]) 
		{
			f[e[i].u].push_back({e[i].v,e[i].w});
			f[e[i].v].push_back({e[i].u,e[i].w});
		}
	}
	while (q--)
	{
		memset(vis1,0,sizeof(vis1));
		ans=0;
		cin>>x>>y;
		dfs(x,y);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
