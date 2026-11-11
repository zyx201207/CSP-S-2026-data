#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), prefix(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; ++i) {
		prefix[i] = prefix[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int t = a[i];
		int l = 1, r = i - 1, idx = -1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (1LL * t * (i - mid) - (prefix[i - 1] - prefix[mid - 1]) <= m) {
				idx = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (idx != -1) {
			ans = max(ans, i - idx + 1);
		}
	}
	cout << ans << endl;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
