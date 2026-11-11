#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int l = 1, r = n, x = a[1], y = a[n];
	long long ans = 0;
	while (1)
	{
		if (x > y)
		{
			if (c[l] != c[r])
				ans += y;
			r--;
			if (l == r)
			{
				cout << ans;
				return 0;
			}
			x -= y;
			y = a[r];
		}
		if (y > x)
		{
			if (c[l] != c[r])
				ans += x;
			l++;
			if (l == r)
			{
				cout << ans;
				return 0;
			}
			y -= x;
			x = a[l];
		}
		if (x == y)
		{
			if (c[l] != c[r])
				ans += x;
			l++;
			r--;
			if (l >= r)
			{
				cout << ans;
				return 0;
			}
			x = a[l];
			y = a[r];
		}
	}
	return 0;
}
