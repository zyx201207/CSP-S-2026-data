/*
Luogu : PigeonTree
qwq
Expected Points : 0'
*/
#include "bits/stdc++.h"
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define ft first
#define sd second
#define pii pair<int, int>
using namespace std;
const int N = 1e6 + 5, INF = 0x3f3f3f3f3f3f3f3fll;
int C, n, k;
vector<int> p[N];
auto init() -> void {
	rep(i, 1, n) p[i].clear();
}
auto check(int mid) -> bool {
	return 1;
}
auto solution() -> void {
	cin >> n >> k;
	rep(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v), p[v].push_back(u);
	}
	int l = 0, r = n, ans = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	cout << ans;
}
auto main() -> signed {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> C >> T;
	while (T--) {
		init();
		solution();
	}
	return 0;
}


