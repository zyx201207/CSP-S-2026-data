#include <bits/stdc++.h>
using namespace std;
int a[500005], b[300005], tmp[500005], w[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int p = 0;
		memset(w, 0, sizeof(w));
		for (int j = i; j <= n; j++)
		{
			if (w[a[j]] == 0)
			{
				p++;
				tmp[p] = a[j];
				w[a[j]] = p;
			}
			else
			{
				for (int z = w[a[j]] + 1; z <= p; z++)
				{
					w[a[z]] = 0;
				}
				p = w[a[j]];
			}
		}
		for (int j = 1; j <= m; j++)
		{
			if (w[j] > 0)
			{
				b[j]++;
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
