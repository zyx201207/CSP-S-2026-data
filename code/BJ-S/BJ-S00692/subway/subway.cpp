#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	long long x, y;
};

bool operator < (node x, node y)
{
	return x.x > y.x;
}

long long c, n, m, d, q, w[1005], k, a, t, l, r, dis[1505][1505], K[505], A[500005], Sum[505], Dis[20005];

vector<node> g[1505];
vector<long long> b[500005];

void dijkstra(long long s)
{
	priority_queue<node> q;
	q.push({s, 0});
	memset(dis[s], 0x3f, sizeof dis[s]);
	dis[s][s] = 0;
	while (q.size())
	{
		node t = q.top();
		q.pop();
		if (dis[s][t.x] != t.y) continue;
		for (node x : g[t.x])
			if (dis[s][x.x] > dis[s][t.x] + x.y)
			{
				dis[s][x.x] = dis[s][t.x] + x.y;
				q.push({x.x, dis[s][x.x]});
			}
	}
}

void bfs(long long s)
{
	queue<node> q;
	for (long long x : b[s]) q.push({x, s});
	memset(Dis, 0x3f, sizeof Dis);
	Dis[s] = 0;
	while (q.size())
	{
		node t = q.front();
		q.pop();
		for (int i = Sum[t.x - 1] + 1; i <= Sum[t.x]; ++i)
			if (Dis[A[i]] > 1e16)
			{
				Dis[A[i]] = Dis[t.y] + 2;
				for (int x : b[A[i]])
					if (x != t.x) q.push({x, A[i]});
			}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if (c <= 11)
	{
		for (int i = 1; i <= m; ++i) cin >> w[i];
		for (int i = 1; i <= n; ++i)
		{
			cin >> k;
			while (k--)
			{
				cin >> a >> t;
				g[a].push_back({m + i, t});
				g[m + i].push_back({a, t});
			}
		}
		for (int i = 1; i <= n + m; ++i) dijkstra(i);
		while (q--)
		{
			cin >> l >> r;
			cout << dis[l][r] + w[l] + w[r] << '\n';
		}
		return 0;
	}
	if (c <= 19)
	{
		for (int i = 1; i <= m; ++i) cin >> w[i];
		for (int i = 1; i <= n; ++i)
		{
			cin >> K[i];
			Sum[i] = Sum[i - 1];
			for (int j = 1; j <= K[i]; ++j) ++Sum[i], cin >> A[Sum[i]] >> t, b[A[Sum[i]]].push_back(i);
		}
		while (q--)
		{
			cin >> l >> r;
			bfs(l);
			cout << Dis[r] * t + w[l] + w[r] << '\n';
		}
		return 0;
	}
	return 0;
}
//🇹 🇼️