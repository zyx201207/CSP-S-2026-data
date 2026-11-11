#include <bits/stdc++.h>
using namespace std;

int a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (m == 1)
	{
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			maxn = max(maxn, x);
		}
		cout << maxn << endl;
	}
	else if (m == 2)
	{
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (i >= 2)
			{
				for (int j = 1; j < i; j++)
				{
					maxn = max(maxn, a[i] & a[j]);
				}
			}
		}
		cout << maxn << endl;
	}
	else
	{
		int flag = true;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] != i - 1)
			{
				flag = false;
			}
		}
		sort(a + 1, a + n + 1);
		if (flag)
		{
			int sum = a[n];
			for (int i = n; i >= 1; i--)
			{
				sum &= a[i];
			}
			cout << sum << endl;
		}
		else
		{
			cout << a[n - m + 1] << endl;
		}
	}
	return 0;
}
