#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e5 + 10;

int n, m, a[N], ans;

signed main()
{
//	string cid; cin >> cid;
//	string input = "crystal" + cid + ".in", output = "crystal" + cid + ".out";
//	freopen(input.c_str(), "r", stdin);
//	freopen(output.c_str(), "w", stdout);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int l = 1, r = 1, sum = 0; r <= n; ++r)
	{
		while (sum > m) sum -= a[r] - a[l], ++l;
//		cout << l << ' ' << r << ' ' << sum << '\n';
		ans = max(ans, r - l + 1);
		sum += (a[r + 1] - a[r]) * (r - l + 1);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
