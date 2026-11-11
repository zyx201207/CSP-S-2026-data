#include<bits/stdc++.h>
using namespace std;
#define MAXM 500010
#define MAXE 500010
#define MAXN 510
#define INF 0x7f7f7f7f7f7f7f7f
int c, n, m, d, q;
int w[MAXM];
struct belong{
	int xian;
	long long t;
};
vector<belong>io[MAXM];
vector<pair<long long, int> > to[MAXN];
long long bian[MAXN][MAXN], min_[MAXN][MAXN];
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > >pq;
bool vis[MAXN];
void dijkstra(int s)
{
	memset(vis, 0, sizeof vis);
	min_[s][s] = 0;
	pq.push({0, s});
	while (!pq.empty())
	{
		int u = pq.top().second;
		long long dist = pq.top().first;
		pq.pop();
		if (vis[u])continue;
		vis[u] = true;
		for (auto i : to[u])
		{
			int v = i.second, w = i.first;
			if (min_[s][v] > dist + w)
			{
				min_[s][v] = dist + w;
				pq.push({min_[s][v], v});
			}
		}
	}	
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	memset (bian, 0x7f, sizeof bian);
	memset (min_, 0x7f, sizeof min_);
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int e = 1; e <= k; e++)
		{
			int a;
			long long t;
			cin >> a >> t;
			for (belong j : io[a])
			{
				bian[j.xian][i] = bian[i][j.xian] = min(bian[j.xian][t], j.t + t);
			}
			io[a].push_back({i,t});
		}
	}
	for (int i = 1;i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i != j && bian[i][j] != INF)
			{
				to[i].push_back({bian[i][j], j});
			}
	}
	for (int i = 1;i <= n; i++)
		dijkstra(i);
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		long long ans0, ans1 = INF;
		cin >> x >> y;
		ans0 = w[x] + w[y];
		for (auto a : io[x])
		{
			for (auto b : io[y])
			{
				ans1 = min (ans1, a.t + b.t + min_[a.xian][b.xian]);
			}
		}
		cout << ans0 + ans1 << endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
