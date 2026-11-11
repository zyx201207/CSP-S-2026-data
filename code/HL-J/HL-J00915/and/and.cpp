#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	long long a[n];
	long long maxn = LLONG_MIN;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i <= n - m; i++)
	{
		long long t = LLONG_MAX;
		for (int j = i + 1; j <= i + m; j++)
		{
			t &= a[j];
		}
		if (t > maxn) maxn = t;
	}
	cout << maxn;
	return 0;
}