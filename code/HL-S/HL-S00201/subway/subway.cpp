#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
vector<vector<long long> > fl(505, vector<long long>(505, 2e18));
vector<int> w(500005);
vector<vector<int> > xl(500005);
vector<vector<int> > xls(500005);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			xl[a].push_back(i);
			xls[a].push_back(t);
			if(xl[a].size() > 1)
			{
				for(int l = 0; l < xl[a].size() - 1; l++)
				{
					long long ne = (long long)t + xls[a][l];
					fl[xl[a][l]][i] = min(ne, fl[xl[a][l]][i]);
					fl[i][xl[a][l]] = min(ne, fl[i][xl[a][l]]);
				}
			}
		}

	}

	for(int i = 1; i <= n; i++) fl[i][i] = 0;
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i < k; i++)
		{
		    if(fl[i][k] >= 1e18) continue;
			for(int j = i + 1; j < k; j++)
			{
				fl[i][j] = min(fl[i][k] + fl[j][k], fl[i][j]);
			}
			for(int j = k + 1; j <= n; j++)
			{
				fl[i][j] = min(fl[i][k] + fl[k][j], fl[i][j]);
			}
		}
		for(int i = k + 1; i < n; i++)
		{
		    if(fl[k][i] >= 1e18) continue;
			for(int j = i + 1; j <= n; j++)
			{
				fl[i][j] = min(fl[k][i] + fl[k][j], fl[i][j]);
			}
		}
	}

	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		long long ans = 4e18;
		for(int j = 0; j < xl[x].size(); j++)
		{
			for(int k = 0; k < xl[y].size(); k++)
			{
				long long cur = fl[min(xl[x][j], xl[y][k])][max(xl[x][j], xl[y][k])];
				ans = min(ans, (long long)xls[x][j] + xls[y][k] + cur);
			}
		}
		cout << ans + w[x] + w[y];
		cout << endl;
	}

	return 0;
}

