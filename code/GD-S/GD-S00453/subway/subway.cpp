#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N = 5e5+5, M = 505;
using ll = long long;
ll walk[N];
vector<pair<ll,ll> > vec[N];
ll g[M][M];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll c, n, m, d, q, i, j, k, x, y, ans;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> m >> n >> d >> q;
	for(i = 1; i <= n; i++)
		cin >> walk[i];
	for(i = 1; i <= m; i++)
	{
		cin >> k;
		for(j = 1; j <= k; j++)
		{
			cin >> x >> y;
			vec[x].push_back(make_pair(i, y));
		}
	}
	memset(g, 0x3f, sizeof(g));
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j < (ll)vec[i].size(); j++)
		{
			for(k = j + 1; k < (ll)vec[i].size(); k++)
			{
				g[vec[i][j].first][vec[i][k].first] = g[vec[i][k].first][vec[i][j].first] = min(vec[i][j].second + vec[i][k].second, g[vec[i][j].first][vec[i][k].first]);
			}
		}
	}
	for(i = 1; i <= m; i++)
	{
		g[i][i] = 0;
	}
	for(k = 1; k <= m; k++)
	{
		for(i = 1; i <= m; i++)
		{
			for(j = 1; j <= m; j++)
			{
				if(i != j && i != k && j != k)
				{
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
	}
	while(q--)
	{
		cin >> x >> y;
		ans = 9e18;
		for(i = 0; i < (ll)vec[x].size(); i++)
		{
			for(j = 0; j < (ll)vec[y].size(); j++)
			{
				ans = min(ans, g[vec[x][i].first][vec[y][j].first] + vec[x][i].second + vec[y][j].second);
			}
		}
		cout << ans + walk[x] + walk[y] << "\n";
	}
	return 0;
}
