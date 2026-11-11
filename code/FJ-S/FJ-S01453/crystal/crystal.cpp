#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a.begin() + 1, a.end());
	for(int i = 1; i <= n; ++ i) pre[i] = pre[i - 1] + a[i];
	auto check = [&](int mid) -> bool {
		for(int j = mid; j <= n; ++ j) {
			int i = j - mid + 1;
			if(a[j] * mid - (pre[j] - pre[i - 1]) <= m) return true;
		}
		return false;
	};
	int l = 1, r = n;
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
