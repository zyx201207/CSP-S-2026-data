#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;

int n, a[N], m, ans;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int r = 1, l = 1; r <= n; r++)
	{
		m -= (a[r] - a[r - 1]) * (r - l);
		
		while(l < r && m < 0) m += a[r] - a[l], l++;
		ans = max(ans,r - l + 1);
//		cout << l << ' ' << r << '\n';
	}
	cout << ans;
	return 0;
} 
