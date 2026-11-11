#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> a[35], f;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, x, ans = 0;
	bool flg;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		for (int j = 31; j > -1; j--)
			if ((x >> j) & 1) a[j].push_back(x);
	}
	x = 31;
	while (x > -1) {
		flg = false;
		for (int j = x - 1; j > -1; j--)
			if (a[j].size() >= m) {
				x = j;
				flg = true;
				break;
			}
		if (!flg) break;
		f = a[x];
		ans = ans | (1 << x);
		for (int i = 0; i <= 31; i++) a[i].clear();
		for (int i = 0; i < f.size(); i++)
			for (int j = 31; j > -1; j--)
				if ((f[i] >> j) & 1) a[j].push_back(f[i]);
	}
	cout << ans;
	return 0;
}
