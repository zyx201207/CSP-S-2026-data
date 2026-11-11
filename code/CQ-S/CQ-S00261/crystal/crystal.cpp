#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
using i64 = long long; using pii = pair<int, int>;
const int N = 5e5 + 10;

i64 a[N], n, m, s[N];

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	rep (i, 1, n) cin >> a[i];
	sort (a + 1, a + n + 1);
	rep (i, 1, n) s[i] = s[i - 1] + a[i];
	i64 cur = 0;
	rep (i, 1, n) {
		i64 l = 1, r = i, ans = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
//		cout << i << ' ' << ans << ' ' << (a[2] * 2 - s[2] <= m) << '\n';
		cur = max(cur, i - ans + 1);
	}
	cout << cur << '\n';
}
