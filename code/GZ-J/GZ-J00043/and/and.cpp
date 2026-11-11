//贵阳市第十九中学 刘承福 GZ-J00043
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	else if (m == n)
	{
		long long ans = a[1] & a[2];
		for (int i = 3; i <= n; i++)
		{
			ans = ans & a[i];
		}
		cout << ans << endl;
	}
	else if (m == 2)
	{
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i != j) ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans << endl;
	}
	else
	{
		long long ans = 0, maxi = 0, maxj = 0, last = 0, maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i] & a[j] > maxn && i != j)
				{
					maxn = a[i] & a[j];
					maxi = i;
					maxj = j;
				}
			}
		}
		ans = maxn;
		a[maxi] = 0;
		a[maxj] = 0;
		for (int i = 1; i <= m-2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (maxn & a[j] > maxn && j != last)
				{
					last = j;
				}
			}
			ans = ans & a[last];
			maxn = maxn & a[last];
			a[last] = 0;
		}
		cout << ans << endl;
	}
	return 0;
}

