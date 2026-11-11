#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, t, n, d, x[2000005], rit[2000005];

namespace Baoli {
	int tmpr[2000005], ok[2000005], sum[2000005], ans[2000005], mxr[2000005], mnr[2000005], totr[2000005];
	void main() {
		int ansss = 0;
		if (c == 11 || c == 12) {
			int bc = rit[1] - 1;
			if (bc == 1 || bc == 0) cout << "0\n";
			else {
				int stps = bc * 2 - 1;
				cout << max(0ll, n - stps) << "\n";
			}
			return;
		}
		for (int i = 1; i <= n; ++i) {
			mxr[i] = 0;
			mnr[i] = 1ll << 60;
			totr[i] = 0;
		}
		for (int r = n; r >= 1; --r) {
			tmpr[r] = r + 1;
			ans[r] = 0;
			sum[r] = 1;
			sum[r + 1] = 0;
			for (int i = r - 1, lit = r; i >= 1; --i) {
				tmpr[i] = min(rit[i], r);
				ans[i] = ans[tmpr[i]] + 1;
				if (tmpr[i] <= i) break;
				lit = min(lit, tmpr[i]);
				while (ans[lit] == ans[lit - 1]) --lit;
				sum[i] = min(3ll, sum[lit] - sum[tmpr[i] + 1]);
				if (sum[i] == 2) {
					++ansss;
				}
				sum[i] += sum[i + 1];
			}
		}
		cout << ansss << "\n";
	}
}

signed main() {
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		for (int l = n, r = n; l >= 1; --l) {
			while (x[r] - x[l] > d) --r;
			rit[l] = r;
		}
	 Baoli::main();
	}
	return 0;
}
// 这真的是题吗  
