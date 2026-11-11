#include<bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;

int c,n,k,dep[N],f[N],dsu[N],mn;
int find(int x)
{
	if (x==dsu[x]) return x;
	return dsu[x]=find(dsu[x]);
}
bool ch[N];
vector<int> g[N];
void dfs(int u,int fa)
{
	f[u]=fa,dep[u]=dep[fa]+1;
	for (int v:g[u])
	{
		if (v==fa) continue;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if (dep[u]<dep[v]) swap(u,v);
	while (dep[u]>dep[v]) u=f[u];
	while (u!=v) u=f[u],v=f[v];
	return u;	
}
int dis(int u,int v) {return dep[u]+dep[v]-2*dep[lca(u,v)];}
void dfs2(int now,int left)
{
	if (left-(n-now+1)>0) return;
	if (now==n+1)
	{
		if (left!=0) return;
		for (int i=1;i<=n;i++) dsu[i]=i;
		for (int i=1;i<=n;i++)
		{
			if (!ch[i]) continue;
			for (int v:g[i])
			{
				if (v!=f[i] && ch[v])
					dsu[find(i)]=find(v);
			}
		}
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (ch[i] && dsu[i]==i)
				cnt++;
		}
		if (cnt>2) return;
		int mx=0;
		for (int i=1;i<=n;i++)
		{
			if (!ch[i]) continue;
			for (int j=1;j<=n;j++)
			{
				if (!ch[j]) continue;
				mx=max(mx,dis(i,j));
			}
		}
		mn=min(mn,mx);
		return;
	}
	dfs2(now+1,left);
	if (left) ch[now]=1,dfs2(now+1,left-1),ch[now]=0;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> c >> T;
	while (T--)
	{
		mn=1e18;
		cin >> n >> k;
		for (int i=1;i<=n;i++)
			g[i].clear();
		int u,v;
		for (int i=1;i<n;i++)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		dfs2(1,k);
		cout << mn << '\n';
	}
	return 0;
}
