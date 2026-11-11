#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[500005], m, delt[500005], ans = 1, l = 1, now, sum[500005];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
	{
		delt[i] = a[i + 1] - a[i];
		sum[i] = sum[i - 1] + delt[i];
//		cout << delt[i] << " ";
	}
//	cout << endl;
	for (int i = 1; i < n; i++)
	{
		now += delt[i] * (i - l + 1);
		while (now > m && l < i)
		{
			now -= (sum[i] - sum[l - 1]);
			l++;
		}
		if (now <= m)
		{
			ans = max(ans, i - l + 2);
		}
	}
	cout << ans << endl;
	return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/
