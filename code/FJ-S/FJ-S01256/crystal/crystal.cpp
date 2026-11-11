#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], res, l, r, mid, maxx, s, ans, c;  
bool flag, resu;
bool f(long long x)
{
	maxx = a[x];
	s = 0;
	for (int i = 1; i <= x; i++)
	{
		s += (maxx - a[i]);
	}
	if (s <= m)
	{
		return 1;
	}
	res = maxx - a[1];
	for (int i = 2; i <= n - x + 1; i++)
	{
		//cout << s << endl; 
		s = s - res + (a[x + i - 1] - a[x + i - 2]) * (x - 1);
		if (s <= m)
		{
			return 1;
		}
		res = a[x + i - 1] - a[i];
	}
	return 0;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	l = 1, r = n;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (f(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
