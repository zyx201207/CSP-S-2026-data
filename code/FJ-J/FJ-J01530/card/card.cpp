#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], now[300005], c[500005], f[500005], ans[300005], fs[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[j] = 1;
			now[j] = 0;
			fs[j] = 0;
		}
		for (int j = i; j <= n; j++)
		{
			if (now[a[j]] != 0)
			{
				for (int l = now[a[j]]; l <= j - 1; l++)
				{
					f[l] = 0;
					now[a[l]] = 0;
				}
			}
			now[a[j]] = j;/*
			for (int k = i; k <= n; k++)
			{
				cout << f[j] << " ";
			}
			cout << endl;*/
		}
		for (int j = i; j <= n; j++)
		{
			//cout << f[j] << " ";
			if (f[j] && !fs[a[j]])
			{
				fs[a[j]] = 1;
				ans[a[j]]++;
			}
			f[j] = 1;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}