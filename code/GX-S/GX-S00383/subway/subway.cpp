#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

const int N = 550, M = 5e5 + 10, Q = 1e5 + 10;
int c, n, m, d, q, head[M + N], tot, w[M];

struct E
{
	int next, to, weight;
} edge[M << 2];
void add(int from, int to, int weight)
{
	edge[++tot] = {head[from], to, weight};
	head[from] = tot;
}

int dis[M << 2], dep[M << 2], vis[M << 2];
void Dijkstra(int x, int p)
{
	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	dis[x] = 0;
	dep[x] = p;
	q.push(make_pair(dis[x], x));
	int u, v, wei;
	while (!q.empty())
	{
		u = q.top().second;
		q.pop();
		if (vis[u] == p)
			continue;
		vis[u] = p;
		for (int i = head[u]; i; i = edge[i].next)
		{
			v = edge[i].to, wei = edge[i].weight;
			if (dis[v] > dis[u] + wei || dep[v] ^ p)
			{
				dis[v] = dis[u] + wei;
				dep[v] = p;
				q.push(make_pair(dis[v], v));
			}
		}
	}
}

struct qus
{
	int x, y, id, ans;
} b[Q];
bool cmp1(qus u, qus v)
{
	return u.x < v.x;
}
bool cmp2(qus u, qus v)
{
	return u.id < v.id;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1, k, a, t; i <= n; i++)
	{
		cin >> k;
		while (k--)
		{
			cin >> a >> t;
			add(a, m + i, t), add(m + i, a, t);
		}
	}
	for (int i = 1; i <= q; i++)
		cin >> b[i].x >> b[i].y, b[i].id = i;
	sort(b + 1, b + q + 1, cmp1);
	for (int i = 1; i <= q; i++)
	{
		if (b[i].x ^ b[i - 1].x)
			Dijkstra(b[i].x, i);
		b[i].ans = dis[b[i].y];
	}	
	sort(b + 1, b + q + 1, cmp2);
	for (int i = 1; i <= q; i++)
		cout << w[b[i].x] + b[i].ans + w[b[i].y] << '\n';

	return 0;
}
