//贵阳市第十九中学 刘承福 GZ-S00032
#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500005], k[505], a[505][500005], t[505][500005];

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
	int cnt = 0;
	for (int i = 1; i <= k[1]; i++)
	{
		for (int j = 1; j <= k[2]; j++)
		{
			if (a[1][i] == a[2][j])
			{
				cnt = a[1][i];
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int xr, yr;
		cin >> xr >> yr;
		long long ans = 0;
		bool fxr1 = false, fyr1 = false, fxr2 = false, fyr2 = false;
		for (int i = 1; i <= k[1]; i++)
		{
			if (a[1][i] == xr)
			{
				fxr1 = true;
			}
			if (a[1][i] == yr)
			{
				fyr1 = true;
			}
		}
		for (int i = 1; i <= k[2]; i++)
		{
			if (a[1][i] == xr)
			{
				fxr2 = true;
			}
			if (a[1][i] == yr)
			{
				fyr2 = true;
			}
		}
		if (fxr1 && fyr1)
		{
			ans += w[xr];
			ans += t[1][xr];
			ans += t[1][yr];
			ans += w[yr];
			cout << ans << endl;
		}
		else if (fxr2 && fyr2)
		{
			ans += w[xr];
			ans += t[2][xr];
			ans += t[2][yr];
			ans += w[yr];
			cout << ans << endl;
		}
		else
		{
			if (fxr1)
			{
				ans += w[xr];
				ans += t[1][xr];
				ans += t[1][cnt];
				ans += t[2][cnt];
				ans += t[2][yr];
				ans += w[yr];
				cout << ans << endl;
			}
			else if (fxr2)
			{
				ans += w[xr];
				ans += t[2][xr];
				ans += t[2][cnt];
				ans += t[1][cnt];
				ans += t[1][yr];
				ans += w[yr];
				cout << ans << endl;
			}
		}
	}
	return 0;
}

