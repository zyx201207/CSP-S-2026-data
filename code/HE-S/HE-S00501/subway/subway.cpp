#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 55, M = 5e2 + 52;
int c, n, m, d, q, w[N], f[M][M];
struct node
{
	int v, w;
};
vector<node> vc[N];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(f, 0x3f, sizeof(f));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int v = 1, k, u, w; v <= n; v++)
	{
		cin >> k;
		while(k--)
		{
			cin >> u >> w;
			for(int i = 0, j, t; i < vc[u].size(); i++)
			{
				j = vc[u][i].v;
				t = vc[u][i].w;
				f[v][j] = f[j][v] = min(f[v][j], w + t);
			}
			vc[u].push_back({v, w});
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for(int i = 1, x, y, mn; i <= q; i++)
	{
		cin >> x >> y;
		mn = 1e18;
		for(int j = 0, u, w; j < vc[x].size(); j++)
		{
			u = vc[x][j].v;
			w = vc[x][j].w;
			for(int k = 0, v, t; k < vc[y].size(); k++)
			{
				v = vc[y][k].v;
				t = vc[y][k].w;
				mn = min(mn, f[u][v] + w + t);
			}
		}
		cout << w[x] + w[y] + mn << endl;
	}
	return 0;
}
