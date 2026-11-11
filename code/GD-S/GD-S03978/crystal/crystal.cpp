//#include <iostream>
//#include <algorithm>
//
//using std::cin;
//using std::cout;
//using std::ios;
//using std::sort;
//using std::lower_bound;
//using std::upper_bound;
//using std::max;

#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500010], sum[500010], ans, res;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = n; i >= 1; i--) {
		long long l = 1, r = i, ans = 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) {
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
//		cout << "i = " << i << "\tans = " << ans << "\n";
		res = max(res, i - ans + 1);
	}
	cout << res << "\n";
	return 0;
}

// Life has no tutorial, so try your best!!

// Jarona!
// Here I come Sanfrandisco!!!
// Flower blooms in your heart.
// No way its your children.
// Heh, its my jarona.
// My king!
// Hey guys, I think I found a glue!
// Dont you like serving human?
