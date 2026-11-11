#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
const int N = 1e6 + 505;
const ll maxn = (ll)1e18;
int nxt[N], to[N], w[N], head[N], E;
int val[N], k[N];
bool vis[N];
ll ans[N], dis[N];
struct node{
	int u;
	ll sum;
	bool operator < (const node & cmp) const
	{
		return cmp.sum < sum;
	}
};
vector<pair<int, int> >st[N];
vector<int> qp;
int n, m, d, c, q;
void add(int u, int v, int Val)
{
	to[E] = v;
	w[E] = Val;
	nxt[E] = head[u];
	head[u] = E++;
}
void dijkstra(int start)
{
	for (int i = 1; i <= m + n; ++i) dis[i] = 1e18, vis[i] = 0;
	dis[start] = 0;
	priority_queue<node>q;
	q.push(node{start, 0});
	while(!q.empty())
	{
		node g = q.top();q.pop();
		if (vis[g.u]) continue;
		vis[g.u] = 1;
		int u = g.u;
		for (int i = head[u]; i != -1; i = nxt[i])
		{
			int v = to[i];
			if (dis[v] > g.sum + w[i])
			{
				dis[v] = g.sum + w[i];
				q.push(node{v, dis[v]});
			}
		}
	}
}
int pl, pr;
int main()
{
	E = 1;
	memset(head, -1, sizeof(head));
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	int now, the_num;
	for (int i = 1; i <= m; ++i) val[i] = read();
	for (int i = 1; i <= n; ++i)
	{
		k[i] = read();
		for (int j = 1; j <= k[i]; ++j)
		{
			now = read();the_num = read();
			add(now, i + m, the_num); 
			add(i + m, now, the_num);
		}
	}
	for (int i = 1; i <= q; ++i)
	{
		pl = read(), pr = read();
		st[pl].push_back(make_pair(i, pr));
		if (!vis[pl]) qp.push_back(pl), vis[pl] = 1;
	}
	int len = qp.size();
	for (int i = 0; i < len; ++i)
	{
		dijkstra(qp[i]);
		int L = st[qp[i]].size();
		for (int j = 0;j < L; ++j)
			ans[st[qp[i]][j].first] = dis[(st[qp[i]][j].second)] + val[qp[i]] + val[st[qp[i]][j].second];
	}
	for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
	return 0;
}
