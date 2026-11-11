#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 8;
int _cid;
int n, k;
int head[N], nxt[N * 2], ver[N * 2], tot = 1;
int dis[N];
bool ins[N];

void add(int u, int v)
{
	nxt[++tot] = head[u], ver[tot] = v, head[u] = tot;
}

int bfs()
{
	deque<int> q;
	memset(dis, 0x3f, sizeof(int) * (n + 2));
	for (int i = 1; i <= n; i++)
		if (ins[i])
		{
			dis[i] = 0;
			q.push_back(i);
		}
	int maxd = 0;
	while (q.size())
	{
		const int u = q.front();
		q.pop_front();
		for (int i = head[u]; i; i = nxt[i])
		{
			const int v = ver[i];
			if (dis[u] + 1 < dis[v])
			{
				dis[v] = dis[u] + 1;
				maxd = max(maxd, dis[v]);
				q.push_back(v);
			}
		}
	}
	return maxd;
}

void solve()
{
	tot = 1;
	memset(head, 0, sizeof(int) * (n + 2));
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	int ans = 0x3f3f3f3f;
	for (int s = 3; s < (1 << n); s++)
	{
		if (__builtin_popcount(s) != k)
			continue;
		int cnt = k;
		for (int i = 1; i <= n; i++)
			ins[i] = (s >> (i - 1)) & 1;
		for (int i = 2; i <= (n - 1) * 2; i += 2)
		{
			if (ins[ver[i]] && ins[ver[i ^ 1]])
				--cnt;
		}
		if (cnt > 2)
			continue;
		int res = bfs();
		ans = min(ans, res);
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T;
	scanf("%d%d", &_cid, &T);
	while (T--)
		solve();
	return 0;
}