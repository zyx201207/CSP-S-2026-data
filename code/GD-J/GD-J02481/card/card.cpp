#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n = 0;
	int m = 0;
	int p[3010]{};
	int a[500010]{};
	int num[3010]{};
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[a[i]] = i;
	}
	if (m > 3000)
	{
		for (int i = 1; i <= n; i++)
		{
			num[a[i]]++;
			if (a[i] != a[i - 1])
			{
				num[a[i]] += num[a[i - 1]];
			}
		}
		for (int i = 1; i <= m; i++)
		{
			cout << num[i] << " ";
		}
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int pt = i;
		while (pt <= n)
		{
			num[a[pt]]++;
			pt = p[a[pt]] + 1;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << num[i] << " ";
	}
	return 0;
}
