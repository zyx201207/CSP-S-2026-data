#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, qc, idx, w[500010], a[500010], b[500010], ans[100010];
int flag[1000010], dis[1000010];
int cnt, h[1000010];
struct edge { int to, w, next; } e[2000010];
struct node { int id, x, y; } query[100010];
bool cmp(node q1, node q2) { return q1.x < q2.x; }
void add(int u, int v, int w)
{
	e[++cnt] = {v, w, h[u]};
	h[u] = cnt;
}
struct qq
{
	int id, dis;
	bool operator <(const qq &x) const { return x.dis < dis; }
};
priority_queue<qq> q;
void dij(int s)
{
	for (int i = 1; i <= idx; i++)
		dis[i] = 2e18, flag[i] = 0;
	q.push({s, 0}), dis[s] = 0;
	while (!q.empty())
	{
		int u = q.top().id;
		q.pop();
		if (flag[u])
			continue;
		flag[u] = 1;
		for (int i = h[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (dis[v] > dis[u] + e[i].w)
				dis[v] = dis[u] + e[i].w, q.push({v, dis[v]});
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &qc), idx = m;
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1, k; i <= n; i++)
	{
		scanf("%lld", &k);
		for (int j = 1; j <= k; j++)
			scanf("%lld%lld", &a[j], &b[j]);
		for (int j = 1; j <= k; j++)
		{
			idx++, add(idx, a[j], b[j]), add(a[j], idx, b[j]);
			if (j < k)
				add(idx, idx + 1, 0), add(idx + 1, idx, 0);
		}
	}
	for (int i = 1, x, y; i <= qc; i++)
		scanf("%lld%lld", &x, &y), query[i] = {i, min(x, y), max(x, y)};
	sort(query + 1, query + qc + 1, cmp);
	for (int i = 1; i <= qc; i++)
	{
		dij(query[i].x);
		ans[query[i].id] = dis[query[i].y] + w[query[i].x] + w[query[i].y];
		while (query[i + 1].x == query[i].x && i + 1 <= qc)
			i++, ans[query[i].id] = dis[query[i].y] + w[query[i].x] + w[query[i].y];
	}
	for (int i = 1; i <= qc; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
