#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], mx;
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
		for (int i = 1; i <= n; i++)
		{
			mx = max(mx, a[i]);
		}
		cout << mx;
	}
	else if (m == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				mx = max(mx, a[i] & a[j]);
			}
		}
		cout << mx;
	}
	else if (m == n)
	{
		mx = a[1];
		for (int i = 2; i <= n; i++)
		{
			mx &= a[i];
		}
		cout << mx;
	}
	else if (m == n - 1)
	{
		for (int i = 1; i <= n; i++) //²»Ñ¡i 
		{
			if (i == n)
			{
				mx = a[1];
			}
			else
			{
				mx = a[i + 1];
			}
			for (int j = 1; j <= n; j++)
			{
				if (j == i) continue;
				mx &= a[i];
			}
		}
		cout << mx;
	}
	else
	{
		sort (a + 1, a + n + 1);
		reverse (a + 1, a + n + 1);
		mx = a[1];
		for (int i = 2; i <= m; i++)
		{
			mx &= a[i];
		}
		cout << mx;
	}
	return 0;
} 
