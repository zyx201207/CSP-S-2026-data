#include <bits/stdc++.h>

using namespace std;

const int LG = 30;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	auto check = [&](int x) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (a[i] & x) == x;
		}
		return cnt >= m;
	};
	int ans = 0;
	for (int k = LG - 1; k >= 0; k--) {
		if (check(ans | (1 << k))) {
			ans |= 1 << k;
		}
	}
	cout << ans << '\n';
	
//	cerr << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

/*

*/
