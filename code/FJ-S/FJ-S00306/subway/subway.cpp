#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c, n, m, d, q, w[500005], k[505], a[505][20002], t[505][20002], tim[505][20002];
vector< pair<ll, ll> > rai[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++)
		cin >> w[i];
	for (ll i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (ll j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			rai[a[i][j]].push_back({i, j});
		}
	}
	for (ll i = 1; i <= q; i++)
	{
		ll x, y;
		cin >> x >> y;
		memset(tim, 0x3f3f3f3f, sizeof(tim));
		queue< pair<ll, ll> > q;
		for (pair<ll, ll> j : rai[x])
		{
			q.push({j.first, x});
			tim[j.first][x] = t[j.first][j.second];
		}
		while (!q.empty())
		{
			pair<ll, ll> u = q.front();
			q.pop();
			ll pos = 0;
			for (pair<ll, ll> j : rai[u.second])
				if (j.first == u.first)
					pos = j.second;
			for (ll j = pos + 1; j <= k[u.first]; j++)
			{
				tim[u.first][a[u.first][j]]
				 = min(tim[u.first][a[u.first][j]]
				 , tim[u.first][u.second]
				 + t[u.first][j]);
				for (pair<ll, ll> l : rai[a[u.first][j]])
				{
					if (l.first != u.first)
					{
						tim[l.first][a[u.first][j]]
						 = min(tim[l.first][a[u.first][j]]
						 , tim[u.first][a[u.first][j]]
						 + t[l.first][l.second]);
						q.push({l.first, a[u.first][j]});
					}
				}
			}
		}
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for (int j = 1; j <= n; j++)
			ans = min(ans, tim[j][y]);
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
 }
 /*
0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7
*/
