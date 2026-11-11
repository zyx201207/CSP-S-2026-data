#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct ch {
	int n;
	char c;
} a[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, ans, cnt, val;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].n >> a[i].c;
	}
	for (int l = 1, r = n; l < r; ) {
		if (a[l].c != a[r].c) {
			cnt = 0;
			while (cnt < a[l].n) {
				val = min(a[r].n, a[l].n - cnt);
				cnt += val;
				a[r].n -= val;
				if (a[r].c != a[l].c) ans += val;
				if (a[r].n == 0) r--;
			}
			l++;
		} else if (a[l].c == a[r].c) {
			if (a[l].n < a[r].n) {
				a[r].n -= a[l].n;
				l++;
				continue;
			}
			if (a[l].n == a[r].n) {
				l++, r++;
				continue;
			}	
			cnt = 0;
			while (cnt < a[l].n) {
				val = min(a[r].n, a[l].n - cnt);
				cnt += val;
				a[r].n -= val;
				if (a[r].c != a[l].c) ans += val;
				if (a[r].n == 0) r--;
			}
			l++;
		}
	}
	cout << ans;
	return 0;
}
