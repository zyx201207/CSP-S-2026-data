#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long LL;
LL c, n, m, d, q, cnt = 0, w[N], k[N];
LL st, ed, dis[N], vis[N];
typedef pair<LL, LL> PII;
vector<PII> G[N];
struct query{LL x, y, id, ans;}qry[N];
bool cmp(query q1, query q2)
{
	if (q1.x != q2.x) return q1.x < q2.x;
	return q1.y < q2.y;
}
bool cmp2(query q1, query q2)
{return q1.id < q2.id;}
void dijkstra()
{
	memset(dis, 0x7f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push({0, st}); dis[st] = 0;
	while (que.size())
	{
		LL x = que.top().second; que.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto i : G[x])
		{
			LL y = i.first, w = i.second;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				que.push({dis[y], y});
			}
		}
	}
}
//1~m£º³öÕ¾¿Ú
//m+1~2m:Õ¾Ìü 
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (LL i = 1; i <= m; i++)
	{
		cin >> w[i];
		G[i].push_back({i + m, w[i]});
		G[i + m].push_back({i, w[i]}); 
	}
	cnt = 2 * m;
	for (LL i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (LL j = 1; j <= k[i]; j++)
		{
			LL a, t; cin >> a >> t;
			a += m;
			G[++cnt].push_back({a, t});
			G[a].push_back({cnt, t});
			if (j == 1) continue;
			G[cnt].push_back({cnt-1, 0});
			G[cnt-1].push_back({cnt, 0});
		}
	}
	for (LL i = 1; i <= q; i++)
	{
		cin >> qry[i].x >> qry[i].y;
		qry[i].id = i;	
	}
	sort(qry + 1, qry + q + 1, cmp); 
	for (LL i = 1; i <= q; i++)
	{
		st = qry[i].x; ed = qry[i].y;
		if (i == 1 or st != qry[i-1].x) dijkstra();
		qry[i].ans = dis[ed];
	}
	sort(qry + 1, qry + q + 1, cmp2);
	for (LL i = 1; i <= q; i++) cout << qry[i].ans << endl;
	return 0;
}
