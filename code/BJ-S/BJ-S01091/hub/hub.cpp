#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<int> G[1000005];
int dep[1000005], Dep[1000005];
int maxi, Maxi;
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	if(dep[u] > dep[maxi]) maxi = u;
	for(auto v : G[u])
	{
		if(v == fa) continue;
		dfs(v, u);
	}
}
void Dfs(int u, int fa)
{
	if(Dep[u] < Dep[fa] + 1) return;
	Dep[u] = Dep[fa] + 1;
	if(Dep[u] > Dep[Maxi]) Maxi = u;
	for(auto v : G[u])
	{
		if(v == fa) continue;
		Dfs(v, u);
	}
}
vector<int> vec;
void mark(int u, int fa, int dis)
{
	vec.push_back(u);
	Dep[u] = 0;
	if(!dis) return;
	for(auto v : G[u])
	{
		if(v == fa) continue;
		mark(v, u, dis - 1);
	}
}
void place(int u, int dis)
{
	int fa = 0, step = dis;
	while(step)
	{
		for(auto v : G[u])
		{
			if(v == fa) continue;
			fa = u;
			u = v;
			break;
		}
		step --;
	}
	mark(u, 0, dis);
}
bool vis[1000005], Vis[1000005];
void dfss(int u, int fa)
{
	if(!vis[u]) return;
	Vis[u] = 1;
	for(auto v : G[u])
	{
		if(v == fa) continue;
		dfss(v, u);
	}
}
bool Check()
{
	int cnt = 0;
	for(int i = 1; i <= n; i ++) Vis[i] = 0;
	for(int i = 1; i <= n; i ++) if(vis[i] && !Vis[i]) dfss(i, 0), cnt ++;
	return cnt <= 2;
}
bool check(int Dis)
{
	if(k <= 2)
	{
		for(int i = 1; i <= n; i ++) Dep[i] = 2e18;
		place(maxi, Dis);
		for(int i = 1; i <= n; i ++)
		{
			if(Dep[i]) break;
			if(i == n) return (1 <= k);
		}
		Maxi = 0;
		for(auto u : vec)
		{
			for(auto v : G[u])
			{
				if(!Dep[v]) continue;
				Dfs(v, u);
			}
		}
		vec.clear();
		place(Maxi, Dis);
		for(int i = 1; i <= n; i ++)
		{
			if(Dep[i]) break;
			if(i == n) return (2 <= k);
		}
		return false;
	}
	int minn = 2e18;
	for(int u = 0; u < (1 << n); u ++)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(!(u & (1 << (i - 1)))) Dep[i] = 2e18, vis[i] = 0;
			else Dep[i] = 0, cnt ++, vis[i] = 1;
		}
		for(int i = 1; i <= n; i ++) if(vis[i]) mark(i, 0, Dis);
		for(int i = 1; i <= n; i ++)
		{
			if(Dep[i] > 0) break;
			if(i == n)
			{
				if(!Check()) break;
				minn = min(minn, cnt);
			}
		}
		vec.clear();
	}
	return (minn <= k);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, _;
	cin >> c >> _;
	while(_ --)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i ++) G[i].clear();
		for(int i = 1; i < n; i ++)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		int l = 1, r = n, mid, ans;
		while(l <= r)
		{
			mid = (l + r) >> 1;
			if(check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
