#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 605;
int c, n, m, d, q;
#define int long long
const int inf = 1e18;
typedef pair<int, int> PII;
struct edge{
	int v, w;
};
vector<edge> e[N];
int cst[N];
bool vis[N];
int dis[N];

void dijkstra(int s)
{
	for(int i = 1; i <= n+m; i++) dis[i] = inf, vis[i] = 0;
	dis[s] = 0;
	priority_queue<PII> q;
	q.push({0, s});
	while(!q.empty())
	{
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(edge ed : e[u])
		{
			int v = ed.v, w = ed.w;
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({-dis[v], v});
			}
		} 
	} 
}
struct query{
	int u, v, ans, idx;
	bool operator<(const query& o) const{
		return u < o.u;
	}
}qry[N];
bool cmp(query x, query y)
{
	return x.idx < y.idx;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> cst[i];
	for(int i = 1; i <= n; i++)
	{
		int len; cin >> len;
		for(int j = 1; j <= len; j++)
		{
			int x, ti; cin >> x >> ti;
			e[x].push_back({m+i, ti});
			e[m+i].push_back({x, ti});
		}
	}
	for(int i = 1; i <= q; i++) cin >> qry[i].u >> qry[i].v, qry[i].idx = i;
	sort(qry+1, qry+1+q);
	for(int i = 1; i <= q; i++)
	{
		if(qry[i].u != qry[i-1].u) dijkstra(qry[i].u);
		qry[i].ans = dis[qry[i].v] + cst[qry[i].u] + cst[qry[i].v];
	}
	sort(qry+1, qry+1+q, cmp);
	for(int i = 1; i <= q; i++) cout << qry[i].ans << endl;
}
/*
*/
