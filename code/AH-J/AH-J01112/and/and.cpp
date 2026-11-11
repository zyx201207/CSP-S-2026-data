#include <bits/stdc++.h>
using namespace std;


int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			ans = max(ans, a[i]&a[j]);
		}
	}
	cout << ans;
	return 0;
}
