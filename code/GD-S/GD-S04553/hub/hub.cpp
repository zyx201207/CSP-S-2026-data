#define ffopen(s) \
cin.tie(0)->sync_with_stdio(0); \
freopen(#s ".in", "r", stdin); \
freopen(#s ".out", "w", stdout); \
//
#include <bits/stdc++.h>
using namespace std;
int C, T, n, k;
namespace A {
	void slove() {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
		}
		int ans1 = (n - k + 1) >> 1;
		int ans2 = 1;
		if (k & 1) {
			ans2 += ((n >> 2) - (k >> 1) + 1) >> 1;
		} else {
			ans2 += (((n + 1) >> 2) - (k >> 1) + 1) >> 1;
		}
		cout << min(ans1, ans2) << '\n';
	}	
}
int main() { ffopen(hub);
	cin >> C >> T;
	while (T--) {
		A::slove();
	}
	return 0;
}
