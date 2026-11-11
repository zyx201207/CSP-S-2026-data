#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 5e5;

int n;
ll m, a[N + 1], s[N + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i + 1;
		while (l + 1 < r) {
			int mid = l + r >> 1;
			int x = i - mid + 1, y = i;
			if ((a[y] * mid) - (s[y] - s[x - 1]) <= m)
				l = mid;
			else
				r = mid;
		}
		ans = max(ans, l);
	}
	cout << ans << '\n';
	return 0;
}
