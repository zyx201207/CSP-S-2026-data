#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2000010;
int n, k, d[N], f[N], s[N], a[N];

void solve1() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(s, 0, sizeof s);
		s[i] = 1, d[i] = 0;
		for (int j = i + 1; j <= n; j++) {
			int p = max((int)(upper_bound(a + 1, a + n + 1, a[j] - k - 1) - a), i);
			if (p == j) d[j] = 0x3f3f3f3f;
			d[j] = d[p] + 1;
			int l = max((int)(upper_bound(d + i, d + j, d[j] - 2) - d), p), r = lower_bound(d + i, d + j, d[j]) - d - 1;
			int val = s[r] - s[l - 1];
			if (val == 2) ans++;
			s[j] = s[j - 1] + val;
		}
	}
	cout << ans << "\n";
}

void Main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	solve1();
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _, T; cin >> _ >> T;
	while (T--) {
		Main();
	}
	return 0;
}
