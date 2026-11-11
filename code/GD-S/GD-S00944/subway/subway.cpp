#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q, w[N], s, t, ans = LLONG_MAX;
bool vis[N];
vector<pair<int, pair<int, int>>> line[N];
vector<pair<pair<int, int>, pair<int, int>>> line_to[N], entery_to[N];
inline int bfs(int s, int st)
{
	memset(vis, false, sizeof(vis));
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for(pair<pair<int, int>, pair<int, int>> p : entery_to[s]) q.push(p);
	while(!q.empty())
	{
		pair<pair<int, int>, pair<int, int>> u = q.front(); q.pop();
		int i = u.first.first, a = u.first.second, k = u.second.first, t = u.second.second;
		vis[a] = true;
		if(a == st) return t;
		for(pair<pair<int, int>, pair<int, int>> p : line_to[i]) if(!vis[a]) q.push(p);
		for(pair<pair<int, int>, pair<int, int>> p : entery_to[a]) if(!vis[a]) q.push({{i, a}, {k, t + t}});
	}
}
inline void dfs(int i, int a, int t)
{
	if(a == t)
	{
		ans = min(ans + t, t);
		return;
	}
	for(pair<pair<int, int>, pair<int, int>> p : line_to[i])
	{
		int nxt = p.second.first;
		if(vis[nxt]) continue;
		vis[nxt] = true;
		dfs(i, nxt, t);
		vis[nxt] = false;
	}
	for(pair<pair<int, int>, pair<int, int>> p : entery_to[a])
	{
		int nxt = p.second.first;
		if(vis[nxt]) continue;
		vis[nxt] = true;
		dfs(p.first.first, nxt, t + p.second.second);
		vis[nxt] = false;
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++)//线 
	{
		int k, a, t;
		cin >> k;
		for(int j = 1; j <= k; j++)//该线的第几站 
		{
			cin >> a >> t;//全市的第几站 和 到站台的时间 
			line[i].push_back({a, {j, t}});
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(pair<int, pair<int, int>> p : line[i])
		{
			int a = p.first, k = p.second.first, t = p.second.second;
			line_to[i].push_back({{i, k}, {a, t}});
			entery_to[a].push_back({{i, a}, {k, t}});
		}
	}
	while(q--)
	{
		cin >> s >> t;
		for(pair<pair<int, int>, pair<int, int>> p : entery_to[s]) dfs(p.first.first, s, p.second.second);
		cout << w[s] + w[t] + ans << endl;
	}
	return 0;
}
