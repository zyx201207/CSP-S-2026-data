#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct Node
{
	int v,w;
	friend bool operator < (const Node &A, const Node &B)
	{
		return A.w > B.w;
	}
};
int dis[N], vis[N], w[N], t[N], d[N], lz[N], rz[N];
vector<Node> G[N];
void dijkstra(int st,int mb)
{
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<Node> q;
	q.push({st, 0});
	dis[st] = 0;
	while (!q.empty())
	{
		int u = q.top().v;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto e : G[u])
		{
			int v = e.v,w = e.w;
			if (!vis[v] && dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
		if (dis[mb] != 0x3f3f3f3f) return; 
	}
	return;
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m, dd,q;
	cin >> c >> n >> m >> dd >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int zs;
		cin >> zs;
		for (int j = 1;j <= zs;j++)
		{
			cin >> d[j] >> t[j];
		}
		for (int j = 1;j < zs;j++)
		{
			for (int k = j + 1;k <= zs;k++)
			{
				G[d[j]].push_back({d[k], t[j] + t[k]});
				G[d[k]].push_back({d[j], t[j] + t[k]});
			}
		}
	}
	for (int i = 1;i <= q;i++)
	{
		int l,r;
		cin >> l >> r;
		dijkstra(l, r);
		cout << dis[r] + w[l] + w[r] << "\n";
	}
	return 0;
}
