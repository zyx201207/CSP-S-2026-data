#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
constexpr int N = 5e5 + 10;
int n, m, a[N], q[N];
int sum(const int l, const int r) {
	return a[r] * (r - l + 1) - (q[r] - q[l - 1]);
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	rep(i, 1, n) {
		q[i] = q[i - 1] + a[i];
	}
	int maxs = 0;
	rep(i, 1, n) {
		int l = 1, r = i, ans = i;
		while (l <= r) {
			const int mid = (l + r) / 2;
			if (sum(mid, i) <= m) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		maxs = max(maxs, i - ans + 1);
	}
	cout << maxs;
	return 0;
}
