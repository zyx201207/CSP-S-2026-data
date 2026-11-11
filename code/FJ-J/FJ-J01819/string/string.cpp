#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 2;

int n, ans1, ans2, l, r, resl, resr, a[N];
char b[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i] >> b[i];
	l = 1, r = n + 1, resl = a[1], resr = 0;
	while (l < r) {
//		cout << "\t" << l << " " << r << " " << resl << " " << resr << endl;
		while (l < r - 1 && resr <= resl) {
			r--;
			if (resl > a[r]) resl -= a[r];
			else {
				if (b[r] != b[l]) ans1 += resl;//, cout << "\tl = " << l << ", r = " << r << ", add2 = " << resl << endl;
				resr += a[r] - resl, resl = 0;
				break;
			}
			if (b[r] != b[l]) ans1 += a[r];//, cout << "\tl = " << l << ", r = " << r << ", add = " << a[r] << endl;
		}
//		cout << "\t" << l << " " << r << " " << resl << " " << resr << endl;
		while (l + 1 < r && resl <= resr) {
			l++;
			if (resr > a[l]) resr -= a[l];
			else {
				if (b[r] != b[l]) ans1 += resr;//, cout << "\tl = " << l << ", r = " << r << ", add2 = " << resr << endl;
				resl += a[l] - resr, resr = 0;
				break;
			}
			if (b[r] != b[l]) ans1 += a[l];//, cout << "\tl = " << l << ", r = " << r << ", add = " << a[r] << endl;
		}
//		cout << "\t" << l << " " << r << " " << resl << " " << resr << endl;
		if (l == r - 1) break;
	}
	cout << ans1 << endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
