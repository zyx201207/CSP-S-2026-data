#include <bits/stdc++.h>
using namespace std;

int a[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, maxn = 0;
	cin >> n >> m;
	cin >> a[1] >> a[2];
	bool flag = true;
	for (int i = 3; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] - a[i - 1] != a[2] - a[1])
		{
			flag = false;
		}
	}
	if (flag)
	{
		long long s = a[2] - a[1];
		long long x = 2 * m / s;
		long long y = ceil(sqrt(x));
		while (y * (y + 1) > m)
		{
			y--;
		}
		cout << y + 1 << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		long long tmp = m, ans = 1;
		int x = i - 1;
		while (a[i] - a[x] <= tmp && x >= 1)
		{
			ans++;
			tmp -= (a[i] - a[x]);
			x--;
		}
		maxn = max(maxn, ans);
	}
	cout << maxn << endl;
	return 0;
}
