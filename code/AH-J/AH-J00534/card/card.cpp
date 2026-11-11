#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500010], f[300010], flg[300010];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	for (int S = 1 ; S <= n ; S++)
	{
		memset(f, 0, sizeof f);
		for (int i = S ; i <= n ; i++)
		{
			if (f[a[i]] == 0)
			{
				f[a[i]] = i;
			}
			else
			{
				for (int j = f[a[i]] ; j < i ; j++)
				{
					f[a[j]] = 0;
				}
				f[a[i]] = i;
			}
		}
		for (int i = 1 ; i <= m ; i++)
		{
			if (f[i] != 0)
			{
				flg[i]++;
			}
		}
	}
	for (int i = 1 ; i <= m ; i++)
	{
		cout << flg[i] << " ";
	}
	return 0;
}
