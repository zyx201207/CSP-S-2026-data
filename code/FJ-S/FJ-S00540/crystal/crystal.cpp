#include <bits/stdc++.h>
using namespace std;
long long a[500005], s[500005], n, m;

bool check(int t)
{
	for (int i = t; i <= n; i++)
		if (a[i] * t - s[i] + s[i - t] <= m)
			return true;
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int l = 1, r = n;
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l;
	return 0;	
}
