#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, n, m, d, q;
ll w[50010];
ll ds[10010][10010];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1;i <= m;i ++)	scanf("%lld", &w[i]);
	
	for (int i = 1;i <= m;i ++)
	{
		for (int j = 1;j <= m;j ++)
		{
			if (i == j) ds[i][j] = 0;
			else ds[i][j] = 0x3f3f3f3f3f3f;
		}
	}
	
	for (int i = 1;i <= n;i ++)
	{
		int k;
		cin >> k;
		int a[100010], t[100010];
		for (int j = 1;j <= k;j ++)
		{
			scanf("%d%d", &a[j], &t[j]);
			for (int l = 1;l < j;l ++)
			{
				ds[a[j]][a[l]] = t[j] * 1ll + t[l];
				ds[a[l]][a[j]] = t[j] * 1ll + t[l];
			}
		}
	}
	for (int k = 1;k <= m;k ++)
	{
		for (int i = 1;i <= m;i ++)
		{
			for (int j = 1;j <= m;j ++)
			{
				ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
			}
		}
	}
	
	
	for (int i = 1, x, y;i <= q;i ++)
	{
		scanf("%d%d", &x, &y);
		ll ans = w[x] + w[y];
		ans += ds[x][y];
		printf("%lld\n", ans);
	}
	
	
	return 0;
}
