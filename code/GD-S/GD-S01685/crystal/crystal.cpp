#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 5e5 + 10;

int n;
i64 m, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		int l = 0, r = i - 1, j = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid) - (s[i] - s[mid]) <= m)
				j = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, i - j);
	}
	cout << ans << "\n";
	return 0;
}
