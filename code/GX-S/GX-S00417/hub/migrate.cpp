#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[1000010];
int fff (long long x, long long y)
{
	for (int i = x; i < y; i++)
	{
		if (a[i+1]-a[i] > d)
			return 0;
	}
	return 1;
}
int main ()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		long long ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n-1; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				if (a[i+1] - a[i] < d && a[i+2] - a[i+1] < d && a[i+2] - a[i] < d && fff(i, j))
					ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
