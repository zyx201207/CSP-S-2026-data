#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e12;
const int N = 500005;
int n, m, a[N], s[N];

void solve() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + 1 + n);
	
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int sum = 0, cnt = 0;
		for (int j = i; j >= 1; --j) {
			if ((sum += a[i] - a[j]) > m) break;
			++cnt;
		}
	}
	
	cout << res << '\n';
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	return 0;
}
