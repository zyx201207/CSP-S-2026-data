#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, m, a[N], ans;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
	{
		if (i * (a[i + 1] - a[i]) > m) break;
		ans = i + 1, m -= i * (a[i + 1] - a[i]);
	} 
	cout << ans;
	return 0;
}
