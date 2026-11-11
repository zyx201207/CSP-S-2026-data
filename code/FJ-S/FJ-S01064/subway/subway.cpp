#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 5e5 + 5, N = 2e4 + 5;
int c, n, m, d, q, a[M], x, y, t[M];
struct edge
{
	ll w, v;
}; 
vector<edge> E[2*M + N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
	{
		ll w;
		cin >> w;
		E[i].emplace_back(edge{w, i + m});
		E[i + m].emplace_back(edge{w, i});
	}
	for (int i = 1, k; i <= n; ++i)
	{
		cin >> k;
		for (int j = 1; j <= k; ++j)
			cin >> a[j] >> t[a[j]];
		for (int j = 1; j < k; ++j)
			for (int l = j + 1; l <= k; ++l){
				E[a[j] + m].emplace_back(edge{t[a[j]] + t[a[l]], a[l] + m});
				E[a[l] + m].emplace_back(edge{t[a[j]] + t[a[l]], a[j] + m});}
	}
	while(q--)
	{
		cin >> x >> y;
		long long dis[2*M+N] = {};
		for(int i = 0; i < N; ++i)
				dis[i] = LONG_LONG_MAX;
		dis[x] = 0;
		
		priority_queue<pair<ll, int>, vector<pair<ll, int>>> qu;
		qu.emplace(pair<ll, int>{0, x});
		while(!qu.empty())
		{
			pair<int, int> e1 = qu.top();
			qu.pop();
			ll w = -e1.first, v = e1.second;
			if (dis[v] != w) continue;
			for (auto e : E[v])
			{
				if (e.v == v) continue;
				if (e.w + w < dis[e.v])
				{
					dis[e.v] = dis[v] + e.w;
					qu.emplace(pair<ll, int>{-dis[e.v], e.v});
				}
			}
		}
		cout << dis[y];
	}
}
