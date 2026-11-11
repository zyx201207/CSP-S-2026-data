#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m; vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> candi = a; int ans = 0;
	for (int b = 29; b >= 0; b--) {
		vector<int> ones;
		for (auto x : candi)
			if (x >> b & 1) ones.push_back(x);
		if (ones.size() >= m) ans |= (1 << b), candi = ones;
	}
	cout << ans;
	/*int ans = -1;
	for (int s = 0; s < (1 << n); s++) {
		if (__builtin_popcount(s) != m) continue;
		int now = (1 << 30) - 1;
		for (int j = 0; j < n; j++)
			if (s >> j & 1) now &= a[j];
		ans = max(ans, now);
	}
	cout << ans;*/
	
	return 0;
}

