#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long c, t;
long long n, a[N], m;
long long dfs1(long long l, long long r, long long step) {
	if(l == r) return step;
	long long ans = LLONG_MAX;
	for (int i = l + 1; i <= r; i++) {
		if(a[i] - a[l] <= m) {
			ans = min(ans, dfs1(i, r, step + 1));
		}
	}
	return ans;
}
long long dfs2(long long l, long long r, long long step, long long minn) {
	if(l == r) {
		if(step == minn) {
			return 1; 
		} else {
			return 0;
		}
	}
	long long ans = 0;
	for (int i = l + 1; i <= r; i++) {
		if(a[i] - a[l] <= m) {
			ans += dfs2(i, r, step + 1, minn);
		}
	}
	return ans;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> m;
		bool flagA = true;
		long long d = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		d = a[2] - a[1];
		for (int i = 3; i <= n; i++) {
			if(a[i] - a[i - 1] != d) {
				flagA = false;
				break;
			}
		}
		if(flagA) {
			if (m < d) {
				cout << 0 << "\n";
				continue;
			}
			long long cnt = m / d;
			if(cnt == 1) {
				cout << 0 << "\n";
				continue;
			}
			long long ans = n - (1 + 2 * (cnt - 1));
			if(ans <= 0) {
				cout << 0 << "\n";
			} else {
				cout << ans << "\n";
			}
			continue;
		}
		if(n <= 2) {
			cout << 0 << "\n";
			continue;
		}
		long long ans = 0;
		for (int l = 1; l < n; l++) {
			for (int r = l + 1; r <= n; r++) {
				long long x = dfs2(l, r, 0, dfs1(l, r, 0));
				if(x == 2) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
		continue;
	}
	return 0;
}
