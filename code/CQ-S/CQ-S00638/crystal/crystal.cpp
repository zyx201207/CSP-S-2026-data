/*
Luogu : PigeonTree
qwq
Crystallized
Expected Points : 100'
*/
#include "bits/stdc++.h"
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define ft first
#define sd second
#define pii pair<int, int>
using namespace std;
const int N = 5e5 + 5, INF = 0x3f3f3f3f3f3f3f3fll;
int n, m, a[N], d[N], s[N];
auto sum(int l, int r) -> int {
	return s[r] - s[l - 1] - (l - 1) * (a[r] - a[l - 1]);
}
auto init() -> void {}
auto solution() -> void {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) {
		d[i] = a[i] - a[i - 1];
		s[i] = s[i - 1] + i * d[i];
	}
	int ans = 1;
	rep(i, 1, n) {
		if (a[i] == a[i - 1]) continue;
		int cnt = 0;
		{
			int j = i;
			while (a[j] == a[i]) cnt++, j++;
		}
		int l = 1, r = i, res = i + 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
//			cout << l << " " << r << " : " << mid << " " << sum(mid + 1, r) << "\n";
			if (sum(mid + 1, i) <= m) {
				r = mid - 1;
				res = mid;
			} else l = mid + 1;
		}
		ans = max(ans, cnt + i - res);
//		cout << i << " " << cnt << " " << res << "\n";
	}
	cout << ans << "\n";
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
auto main() -> signed {
//	freopen("crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) {
		init();
		solution();
	}
	return 0;
}

