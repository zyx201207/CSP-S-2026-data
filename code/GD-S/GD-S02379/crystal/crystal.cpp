#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = 0;
	int m = 0;
	long long a[500010]{};
	long long c[500010]{};
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++)
	{
		c[i] = a[i] - a[i - 1];
	}
	long long dp[500010]{};
	for (int i = 1; i < n; i++)
	{
		dp[i] = dp[i - 1] + i * c[i]; 
	}
	int l = 0;
	int r = 1;
	int ans = 1;
	while (r < n)
	{
		long long cmp = (r - l) * c[r] - dp[l] + dp[r - 1];
		if (cmp > m)
		{
			l++;
			if (l == r)
			{
				r++;
			}
		}
		else
		{
			ans = max(ans, r - l + 1);
			r++;
		}
	}
	cout << ans;
	return 0;
}
