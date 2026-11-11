#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[1000], k[505], x, y,num;
long long a[505][1000], t[505][1000];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j k[i]; j++)
		{
		    num += t[i][j];
		}
	}
	num += w[x] + w[y];
	cout << num;
	return 0;
}
