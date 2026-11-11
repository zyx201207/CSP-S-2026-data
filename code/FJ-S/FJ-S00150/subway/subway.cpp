#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int c, n, m, d, q; long long w[N], f[505][505];

struct edge
{
	int to; long long w;
};
vector <edge> e[N];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++)
	{
		int len;
		cin >> len;
		for (int j = 1; j <= len; j ++) 
		{
			int x; long long t;
			cin >> x >> t;
			e[x].push_back({i, t});
		}
	}
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
			f[i][j] = 1e18;		
		f[i][i] = 0;
	}

	for (int i = 1; i <= m; i ++)
		for (int j = 0; j < e[i].size(); j ++)
			for (int k = 0; k < e[i].size(); k ++)
			{
				if (j == k) continue;
				edge x = e[i][j], y = e[i][k];
				f[x.to][y.to] = f[y.to][x.to] = x.w + y.w; 
			}
			
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	while (q --)
	{
		int x, y; long long ans = 1e18;
		cin >> x >> y;
		for (int i = 0; i < e[x].size(); i ++)  
			for (int j = 0; j < e[y].size(); j ++)
				ans = min(ans, e[x][i].w + f[e[x][i].to][e[y][j].to] + e[y][j].w);
		cout << w[x] + ans + w[y] << "\n";
	}
	return 0;
}
