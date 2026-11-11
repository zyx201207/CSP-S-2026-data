#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n; i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		for (int i = 1; i <= n; i ++)
		{
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	}
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			ans = max(a[j] & a[i], ans);
		}
	}
	cout << ans;
	return 0;
}
