#include <bits/stdc++.h>

#define int long long

using namespace std;

namespace zcq_qwq {
	const int N = 5e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;
	
	int n, m; 
	
	int a[N], sum[N];
	
	bool check(int mid) {
		for (int i = 1; i + mid - 1 <= n; i++) {
			if (a[i + mid - 1] * mid - sum[i + mid - 1] + sum[i - 1] <= m) return true;
		}
		return false;
	}
	
	void main() {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + a[i];
		}
		int l = 1, r = n;
		int ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		cout << ans;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	zcq_qwq::main();
	return 0;
}

/*
显然贪心
直接贪心不对
二分能合成的最大的大小是多少
显然大小越大，数量越多 
*/
