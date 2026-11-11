#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; i64 m; cin >> n >> m; vector<i64> a(n);
	for (int i = 0; i < n; i++) cin >> a[i]; sort(a.begin(), a.end());
	
	vector<i64> pre(n + 1);
	for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l = 0, r = i, pos = -1;
		auto check = [&](int j) {
			return a[i] * (i - j + 1) - pre[i + 1] + pre[j] <= m;
		};
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) r = mid - 1, pos = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - pos + 1);
	}
	cout << ans;
	
	// Brute force
	/*int ans = 0;
	for (int i = 0; i < n; i++) {
		// fill a[j] that j <= i
		auto check = [&](int j) {
			return a[i] * (i - j + 1) - pre[i+1] + pre[j] <= m;
		};
		int p = i;
		while (p > 0 && check(p - 1)) p--;
		ans = max(ans, i-p+1);
	}
	cout << ans;*/
	
	return 0;
}

