#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 5e5 + 100;

int n, m, ans, sum;
int a[maxn];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];

	sort(a + 1, a + n + 1);

	int l = 1;
	
	for (int r = 1; r <= n; r ++)
	{
		sum += (r - l) * (a[r] - a[r - 1]);
		while (sum > m && l <= r)
		{
			sum -= (a[r] - a[l ++]);
		}
		ans = max(r - l + 1, ans);
	}
	
	cout << ans << "\n";
}
