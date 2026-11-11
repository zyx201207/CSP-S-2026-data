#include <bits/stdc++.h>
using namespace std;
struct note
{
	long long line, t;
};
vector <note> h[500005];
long long c, n, m, d, q, w[500005], k[1005], a[505][25], t[505][25], u, v, ans,add;
bool f[500005];
void search(long long u, long long now, long long l)
{
	//cout << u << " " << now << " " << l << endl; 
	add = 0;
	if (ans != -1 && ans <= now)
	{
		return ;
	}
	for (int i = 0; i < h[u].size(); i++) 
	{
		for (int j = 1; j <= k[h[u][i].line]; j++)
		{
			if (l == h[u][i].line)
			{
				add = h[u][i].t;
				break;
			}
		}
	}
	now += add;
	if (u == v)
	{
		ans = now + w[u];
		return ;
	}
	for (int i = 0; i < h[u].size(); i++) 
	{
		for (int j = 1; j <= k[h[u][i].line]; j++)
		{
			if (l == h[u][i].line)
			{
				break;
			}
			if (a[h[u][i].line][j] == u || f[a[h[u][i].line][j]] == 1)
			{
				continue;
			}
			f[a[h[u][i].line][j]] = 1;
			//cout << now << endl;
			search(a[h[u][i].line][j], now + h[u][i].t, h[u][i].line);
			f[a[h[u][i].line][j]] = 0;
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
		//h[i].push_back({0, w[i]});
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			h[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> u >> v;
		ans = -1;
		search(u, w[u], 0);
		cout << ans << endl;
	}
	return 0;
}
