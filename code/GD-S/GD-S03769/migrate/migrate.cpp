#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e6+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

/*
题意:
有 n 个节点的链式图, 每个节点有一个点权 xi
从 i 到 j 的移动条件: |xi-xj| <= d
定义双径岛屿对(u,v)的条件: u 到 v 的最短路恰有两条
求双径岛屿对的数量
*/ 

int n,s,t; // 此 t 非彼 t 
ll a[maxn], d, ans, dist; // dist:最短路长度 
int f; // 有几条最短路 
vector<int> g[maxn]; 
bool vis[maxn];

void get(int u, ll dis) // GET最短路长度 
{
	if(u == t)
	{
		dist = min(dis,dist);
		return;
	}
	vis[u] = 1;
	for(auto &v : g[u])
	{
		if(vis[v]) continue;
		get(v, dis+1);
	}
	vis[u] = 0;
}

void dfs(int u, ll dis) // 有多少个路径和最短路长度一样长 
{
	if(u == t)
	{
		if(dis == dist) f++;
		return;
	}
	vis[u] = 1;
	for(auto &v : g[u])
	{
		if(vis[v]) continue;
		dfs(v, dis+1);
	}	
	vis[u] = 0;
}

void solve()
{
	cin>>n>>d;
	ans = 0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		g[i].clear();
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(a[i]-a[j]) <= d)
			{
				g[i].push_back(j);
				g[j].push_back(i);
			} 
		}
	}
	
	for(s=1;s<=n;s++)
	{
		for(t=s+1;t<=n;t++)
		{
			for(int i=1;i<=n;i++) vis[i] = 0;
			dist = INF;
			f = 0;
			get(s, 0);
			for(int i=1;i<=n;i++) vis[i] = 0;
			dfs(s, 0);
			if(f == 2) ans++;
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c,t; cin>>c>>t; while(t--) solve();
	
	return 0;
} 
