#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], ans[300005], tb[500005];
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
		memset(tb, 0, sizeof(tb));
		int rr = 1;
		for (int j = i; j <= n; j++)
		{
			int idx = rr;
			for (int k = 1; k <= rr; k++)
			{
				if (tb[k] == a[j])
				{
					idx = k;
					break;
				}
			}
			if (tb[idx] == a[j])
			{
				rr = idx + 1;
			}
			else
			{
				tb[rr++] = a[j];
			}
		}
		for (int j = 1; j < rr; j++)
		{
			ans[tb[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
