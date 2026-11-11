#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
const ll inf = 1e18;
int c, n, m, d, q, idx;
int num[505];
ll x[N], dis[N];
struct edge
{
	int v;
	ll w;
}  ;
vector<edge> g[N];
map<pair<int, int>, int> mp;
queue<int> qu;
inline void add(int u, int v, ll w)
{
	g[u].push_back({v, w});
	g[v].push_back({u, w});
}
inline ll bfs(int s, int e)
{
	qu.emplace(s);
	for (int i = 1; i <= idx; i++) dis[i] = inf; 
	dis[s] = 0;
	while (!qu.empty())
	{
		int u = qu.front();
		qu.pop();
		for (auto i : g[u])
		{
			if (dis[i.v] > dis[u] + i.w)
			{
				dis[i.v] = dis[u] + i.w;
				qu.emplace(i.v);
			}
		}
	}
	return dis[e];
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> x[i];
		mp[{0, i}] = ++idx;
	}
	for (int i = 1; i <= n; i++)
	{
		int u, v;
		ll t;
		cin >> num[i] >> u >> t;
		mp[{i, 1}] = ++idx;
		add(idx, mp[{0, u}], t);
		for (int j = 2; j <= num[i]; j++)
		{
			cin >> v >> t;
			mp[{i, j}] = ++idx;
			add(idx, mp[{0, v}], t);
			add(mp[{i, j-1}], mp[{i, j}], 0);
		}
	}
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		cout << bfs(u, v)+x[u]+x[v] << "\n";
	}
	return 0;
}
/*


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


第1条：
1,1->6|1,2->7|1,3->8|
第2条：
2,1->9|2,2->10|2,3->11|









*/
