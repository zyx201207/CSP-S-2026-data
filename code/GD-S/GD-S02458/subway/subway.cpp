#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int N(5e5 + 5);
struct road
{
	int v, w;
	road() {}
	road(const int &v, const int &w) : v(v), w(w) {}
	bool operator<(const road &b) const
	{
		return b.w > w;
	}
};
priority_queue<road> pq;
vector<road> v[N];
int dis[N];
bool vis[N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int c, m, n, d, q;
	cin >> c >> m >> n >> d >> q;
	for (int i = 1, wi; i <= n; i++)
	{
		cin >> wi;
		v[i].emplace_back(0, wi);
		v[0].emplace_back(i, wi);
	}
	for (int i = 1, k, last, ui, wi; i <= m; i++)
	{
		cin >> k >> last >> wi;
		for (int j = 2; j <= k; j++)
		{
			v[last].emplace_back(n + 1, wi);
			v[n + 1].emplace_back(last, wi);
			cin >> ui >> wi;
			v[ui].emplace_back(last, 0);
			v[last].emplace_back(ui, 0);
			last = ui;
		}
	}
	for (int i = 0; i <= n + 1; i++)
	{
		for (road &it : v[i])
		{
			cout << it.w << ' ';
		}
		cout << '\n';
	}
	for (int i = 1, ui, vi; i <= q; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dis[j] = 0x7FFFFFFF;
			vis[j] = false;
		} 
		cin >> ui >> vi;
		pq.emplace(1, 0);
		while (!pq.empty())
		{
			int u = pq.top().v;
			pq.pop();
			if (vis[u])
			{
				continue;
			}
			vis[u] = true; 
			for (road &it : v[u])
			{
				if (dis[u] + it.w < dis[it.v])
				{
					dis[it.v] = dis[u] + it.w;
					pq.emplace(it.v, dis[it.v]);
				}
			}
		}
		cout << dis[vi] << '\n';
	}
	return 0;
} 
