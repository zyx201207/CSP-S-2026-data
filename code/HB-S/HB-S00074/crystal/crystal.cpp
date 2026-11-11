#include <bits/stdc++.h>

using namespace std;
using LL = long long;
const int MAXN = 5e5 + 10;

int n; LL a[MAXN], sum[MAXN];
LL m;

inline LL val(int l, int r) {
	return sum[r] - sum[l - 1];
}

bool check(int x, int p) {
	LL tot = a[p] * (p - x);
	return (tot - val(x, p - 1)) <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1); int ans = 0;
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i) {
		// LL need = 0; int cnt = 0;
		// for (int j = i - 1; j > 0; --j) {
		// 	if (need + (a[i] - a[j]) > m)
		// 		break;
		// 	++cnt; need += a[i] - a[j];
		// }
		int l = 1, r = i - 1, res = -1;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) {
				res = mid;
				r = mid;
			}
			else {
				l = mid;
			}
		}
		if (res == -1) 
			continue;
		ans = max(ans, (i - res + 1));
	}
	cout << ans;
	return 0;
}