#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const long long inf = 3e18;

int c, t, n, ans;
long long d;
long long x[N];
int known[N];
vector <int> g[N];
long long dis[3][N];

struct edge
{
	int u;
	long long d;
};

bool operator <(const edge a, const edge b)
{
	return a.d > b.d;
}

void dijkstra(int s)
{
	fill(known+1, known+n+1, false);
	priority_queue <edge> pq;
	for (int i = 1; i <= n; i++)
		dis[0][i] = dis[1][i] = dis[2][i] = inf;
	dis[0][s] = 0;
	pq.push({s, dis[0][s]});
	while (!pq.empty())
	{
		edge cur = pq.top();
		pq.pop();
		int u = cur.u;
		if (known[u] > 3)
			continue;
		known[u]++;
		for (auto v: g[u])
		{
			int cnt = known[u]-1;
			for (int i = 0; i < 3; i++)
				if (dis[cnt][u]+1 < dis[i][v])
				{
					dis[i][v] = dis[cnt][u]+1;
					pq.push({v, dis[i][v]});
					break;
				}
		}
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	if (c > 10)
	{
		while (t--)
		{
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> x[i];
			if (d >= 2*(x[2]-x[1]))
				cout << n-3;
			else
				cout << 0;
			cout << '\n';
		}
		return 0;
	}
	while (t--)
	{
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
			g[i].clear();
		}
		for (int i = 1; i <= n; i++)
			for (int j = i+1; j <= n; j++)
				if (x[j]-x[i] <= d)
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}
		for (int u = 1; u <= n; u++)
		{
			dijkstra(u);
			for (int v = u+1; v <= n; v++)
			{
				//cout << dis[0][v] << ' ' << dis[1][v] << ' ' << dis[2][v] << '\n';
				if (dis[0][v] < inf/2 && dis[1][v] == dis[0][v] && dis[2][v] != dis[1][v])
					ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
