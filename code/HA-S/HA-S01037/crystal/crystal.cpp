#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], f[500005], b, ans;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	bool flag = true;
	for (long long i = 1; i < n - 1; i++)
	{
		if (a[i + 1] - a[i] != a[i + 2] - a[i + 1])
		{
			flag = false;
			break;
		}
		else
		{
			b = a[i + 1] - a[i];
		}
	}
	if (flag)
	{
		ans = 1;
		for (long long i = 1; i < n; i++)
		{
			m -= b * i;
			if (m < 0)
			{
				break;
			}
			ans = i + 1;
		}
	}
	else
	{
		for (long long i = 1; i <= n; i++)
		{
			memset(f, 0, sizeof(f));
			for (long long j = 1; j < i; j++)
			{
				for (long long k = m; k >= (a[i] - a[j]); k--)
				{
					f[k] = max(f[k], f[k - (a[i] - a[j])] + 1);
				}
			}
			ans = max(ans, f[m] + 1);
		}
	}
	cout << ans;
	return 0;
}