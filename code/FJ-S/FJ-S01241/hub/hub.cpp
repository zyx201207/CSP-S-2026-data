#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,dep[2000005],fa[2000005][25],ans;
vector<int> b[2000005];
bool vis[2000005],flag[2000005]; 
void dfs(int u,int f)
{
	dep[u] = dep[f]+1;
	fa[u][0] = f;
	for(int i = 1;i <= 22;i++) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(auto v:b[u])
	{
		if(v == f) continue;
		dfs(v,u); 
	}
}
int lca(int u,int v)
{
	if(dep[u] < dep[v]) swap(u,v);
	for(int i = 22;i >= 0;i--)
	{
		if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	}
	if(u == v) return u;
	for(int i = 22;i >= 0;i--)
	{
		if(fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}
void dfs3(int u,int f)
{
	flag[u] = 1;
	for(auto v:b[u])
	{
		if(v == f || !vis[v]) continue;
		dfs3(v,u);
	}
}
bool check()
{
	int res = 0;
	for(int i = 1;i <= n;i++) flag[i] = 0;
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] && !flag[i])
		{
			res++;
			dfs3(i,0);
		}
	}
	return res <= 2;
}
int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
int d(int now)
{
	int minn = 1e18;
	for(int i = 1;i <= n;i++)
	{
		if(vis[i]) minn = min(minn,dis(now,i)); 
	}
	return minn;
}
int f()
{
	int maxx = 0;
	for(int i = 1;i <= n;i++) maxx = max(maxx,d(i));
	return maxx;
}
void dfs2(int x,int tot)
{
	if(tot == k)
	{
		if(check()) ans = min(ans,f());
		return;
	}
	if(x >= n+1) return;
	vis[x] = 1;
	dfs2(x+1,tot+1);
	vis[x] = 0;
	dfs2(x+1,tot);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1;i <= n;i++)
		{
			b[i].clear();
			dep[i] = 0;
			for(int j = 0;j <= 22;j++) fa[i][j] = 0;
		}
		for(int i = 1,u,v;i <= n-1;i++)
		{
			cin >> u >> v;
			b[u].push_back(v);
			b[v].push_back(u);
		}
		if(c == 13 || c == 14)
		{
			if(k >= n/2) cout << "1\n";
			else cout << max(0ll,(int)ceil(((n+1)/2-k)/4.0))+1 << "\n";
		}
		else
		{
			dfs(1,0);
			ans = 1e18;
			dfs2(1,0);
			cout << ans << "\n";
		}
	}
	return 0;
}
