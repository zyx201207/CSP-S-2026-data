#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500001], ans, cnt = 1;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	while (m--)
	{
		a[1]++;
		sort(a+1, a+n+1);
	}
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > a[i-1])
		{
			ans = max(ans, cnt);
			cnt = 1;
		}
		else
		{
			cnt++;
		}
	}
	cout << ans;
	return 0;
}
