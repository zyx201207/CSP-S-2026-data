#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
int c, n, m, d, q;
long long ans, w[500010], dis[510], dd[510][510];
vector<pair<long long, long long> > con[501010], g[510];
long long gg[510][510];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

int main()
{
	//update 1706:ÑùÀýÈ«¹ý 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	int l = 0, v = 0;
	long long len = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> l;
		for (int j = 0; j < l; j++)
		{
			cin >> v >> len;
			con[v].emplace_back(i, len);
		}
	}
	for (int i = 1; i <= m; i++)
		for (pair<int, long long> nxt1 : con[i])
			for (pair<int, long long> nxt2 : con[i])
				if (nxt1.first != nxt2.first)
				{
					if (gg[nxt1.first][nxt2.first] != 0)
						gg[nxt1.first][nxt2.first] = min(gg[nxt1.first][nxt2.first], nxt1.second + nxt2.second);
					else
						gg[nxt1.first][nxt2.first] = nxt1.second + nxt2.second;
				}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (gg[i][j])
			{
				g[i].emplace_back(j, gg[i][j]);
				g[j].emplace_back(i, gg[i][j]);
			}
	for (int i = 1; i <= n; i++)
	{
		memset(dis, 0x3f, sizeof dis);
		pq.emplace(0, i);
		dis[i] = 0;
		while (!pq.empty())
		{
			int u = pq.top().second;
			long long d = pq.top().first;
			pq.pop();
			if (dis[u] < d)
				continue;
			for (pair<int, long long> nxt : g[u])
			{
				int v = nxt.first;
				long long w = nxt.second;
				if (dis[v] > d + w)
				{
					dis[v] = d + w;
					pq.emplace(dis[v], v);
				}
			}
		}
		for (int j = 1; j <= n; j++)
			dd[i][j] = dis[j];
	}
	int u;
	for (int i = 1; i <= q; i++)
	{
		ans = 0x3ffffffffffffff;
		cin >> u >> v;
		for (pair<int, long long> nxt1 : con[u])
		{
			for (pair<int, long long> nxt2 : con[v])
			{
				int x = nxt1.first, y = nxt2.first;
				ans = min(ans, dd[x][y] + nxt1.second + nxt2.second);
			}
		}
		ans += w[u] + w[v];
		cout << ans << '\n';
	}
}
