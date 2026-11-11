#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pii;
const int N = 6e5 + 5;
const long long inf = 1e15;
vector<pair<int, long long>> g[N];
long long dis[N], E[N], ans[N];
int n, m;

struct chaxun
{
	int st, ed, id;
	bool operator < (const chaxun& o) const {
		return st < o.st;
	}
} cha[100005];

void bfs(int st)
{
	for (int i = 1; i <= n + m; i++) dis[i] = inf;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0, st});
	dis[st] = 0;
	
	while (!q.empty())
	{
		auto [d, u] = q.top();
		q.pop();
		if (d > dis[u]) continue;
		
		for (auto [v, w] : g[u])
		{
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T, d, Q, len, u, w;
	cin >> T >> m >> n >> d >> Q; // m, n反过来：n个点，m条线路 
	
	for (int i = 1; i <= n; i++) cin >> E[i]; // 站厅到出站口的时间 
	
	for (int i = 1; i <= m; i++)
	{
		cin >> len;
		for (int j = 1; j <= len; j++)
		{
			cin >> u >> w;
			g[u].push_back({n + i, w});
			g[i + n].push_back({u, w}); // 把线路压缩成点（i号线记为n+i），经过的站的站厅和线路点连边（时间为边权） 
		}
	}
	
	for (int i = 1; i <= Q; i++)
	{
		cin >> cha[i].st >> cha[i].ed;
		cha[i].id = i;
		if (cha[i].st < cha[i].ed) swap(cha[i].st, cha[i].ed);
	}
	sort(cha + 1, cha + Q + 1);
	
	for (int i = 1; i <= Q; i++)
	{
		if (i == 1 || cha[i].st != cha[i - 1].st) bfs(cha[i].st); // 起点相同，只做一次最短路即可(小优化)
		ans[cha[i].id] = dis[cha[i].ed] + E[cha[i].st] + E[cha[i].ed];
		if (cha[i].st == cha[i].ed) ans[cha[i].id] = 0;
	}
	
	for (int i = 1; i <= Q; i++) cout << ans[i] << "\n";
	return 0;
}


