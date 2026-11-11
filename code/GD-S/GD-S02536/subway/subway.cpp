#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], a[505][500005], t[505][500005], k[505], x[100005], y[100005];
vector<int> g[500005];

int main()
{
	//inserting:
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &k[i]);
		for(int l = 1; l <= k[i]; l++)
		{
			scanf("%d %d", &a[i][l], &t[i][l]);
		}
	}
	for(int i = 1; i <= q; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	
	//programming:
	for(int i = 1; i <= n; i++)
	{
		for(int l = 2; l <= k[i]; l++)
		{
			int u = a[i][l], v = a[i - 1][l];
			g[v].push_back(u);
			g[u].push_back(v);
		}
	}
	return 0;
}

