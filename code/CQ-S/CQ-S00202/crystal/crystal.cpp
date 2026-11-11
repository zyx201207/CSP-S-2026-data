#include <bits/stdc++.h>
using namespace std;

#define DEBUG
#define LOCAL

typedef long long int ll;
typedef unsigned long long int ull;
#define int ll

const int N = 5e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, k, cnt, ans;
int a[N], sum[N];

inline int binary_bound_search(int R) {
	int l = 1, r = R;
	int ans = 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (mid * a[R] - (sum[R] - sum[R - mid]) <= m) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	
	return ans;
} 

inline void solve() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		ans = max(ans, binary_bound_search(i));
	}
	
	cout << ans << "\n";
}
#undef int
int main(int argc, const char* argv[]) {
#define int ll
#ifdef LOCAL
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
//	cin >> t;

	while (t --) {
		solve();

	}

	return 0;
}

