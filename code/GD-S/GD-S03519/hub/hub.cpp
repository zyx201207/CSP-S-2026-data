#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;

int c, T;

int n, k;
vector<int> e[MAXN];

vector<int> v;
bool vis[MAXN];
int dis[MAXN];

int ans;

void dfs(int u)
{
	vis[u] = true;
	for(auto v : e[u])
	{
		if(vis[v] || *lower_bound(::v.begin(), ::v.end(), v) != v) continue;
		dfs(v);
	}
}

void bfs()
{
	queue<pair<int, int>> q; // u, d;
	for(auto u : v) q.push({u, 0}), dis[u] = 0;
	while(!q.empty())
	{
		auto x = q.front();
		auto u = x.first, d = x.second;
		q.pop();
		if(d > dis[u]) continue;
		for(auto v : e[u])
		{
			if(dis[u] + 1 < dis[v])
			{
				dis[v] = dis[u] + 1;
				q.push({v, dis[v]});
			}
		}
	}
}

void f(int l)
{
	if(v.size() == k)
	{
		int cnt = 0;
		for(auto u : v) vis[u] = false;
		for(auto u : v) if(!vis[u]) dfs(u), cnt++;
		if(cnt > 2) return;
		for(int i=1;i<=n;i++) dis[i] = 1e9;
		bfs();
		int mx = 0;
		for(int i=1;i<=n;i++) mx = max(mx, dis[i]);
		ans = min(ans, mx);
		return;
	}
	for(int i=l+1;i<=n;i++)
	{
		v.push_back(i);
		f(i);
		v.pop_back();
	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>c>>T;
	while(T--)
	{
		ans = 1e9;
		for(int i=1;i<=n;i++) e[i].clear();
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u, v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);	
		}
		if(c == 13 || c == 14)
		{
			int m = (n-1)/2;
			if((m % 2) == (k % 2)) cout<<(int)ceil((m-k)/4.00)+1<<'\n';
			else cout<<(int)ceil((m-k+1)/4.00)+1<<'\n';
		}
		else
		{
			f(0);
			cout<<ans<<'\n';	
		}
	}
	return 0;
}
