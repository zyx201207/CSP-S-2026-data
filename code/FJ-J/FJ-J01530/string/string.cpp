#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], b[200005], ans, l, r;
char c[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	ans = 0;
	l = 1, r = n;
	while (l < r)
	{
		if (a[l] > a[r])
		{
			if (c[l] != c[r])
			{
				ans += a[r];
			}
			a[l] -= a[r];
			r--;
		}
		if (a[l] == a[r])
		{
			if (c[l] != c[r])
			{
				ans += a[r];
			}
			l++;
			r--;
		}
		if (a[l] < a[r])
		{
			if (c[l] != c[r])
			{
				ans += a[l];
			}
			a[r] -= a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}