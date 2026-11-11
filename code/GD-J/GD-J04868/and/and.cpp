#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> v, v1;
	for (int i = 30; i >= 0; i--) {
		if (v.empty()) {
			int cnt = 0;
			for (int j = 1; j <= n; j++) if (((a[j] >> i) & 1)) cnt++;
			if (cnt < m) continue;
			for (int j = 1; j <= n; j++) if (((a[j] >> i) & 1)) v.push_back(a[j]);
			sum += (1LL << i);
		} else {
			int cnt1 = 0;
			for (auto x : v) if (((x >> i) & 1)) cnt1++;
			if (cnt1 < m) continue;
			v1.clear();
			for (auto x : v) if (((x >> i) & 1)) v1.push_back(x);
			v = v1;
			sum += (1LL << i);
		}
	}
	cout << sum << '\n';
	return 0;
}
