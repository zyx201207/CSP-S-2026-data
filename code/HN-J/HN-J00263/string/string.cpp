#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10;

struct node{
	int val;
	char c;
}a[N], lft;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].val >> a[i].c;
	}
	int l = 1, r = n, ans = 0;
	while (l < r) {
		if (a[l].val > a[r].val) {                     
			while ((a[l].val  - a[r].val) >= 0 && l < r) {
				if (a[l].c != a[r].c) {
					ans += a[r].val;
				}
				a[l].val -= a[r].val;
				r--;
			}
			if (l < r) {
				if (a[l].c != a[r].c) {
					ans += a[l].val;
				}
				a[r].val -= a[l].val;
				a[l].val = 0;
				l++;
			}
		}
		else {
			while ((a[r].val  - a[l].val) >= 0 && l < r) {
				if (a[l].c != a[r].c) {
					ans += a[l].val;
				}
				a[r].val -= a[l].val;
				l++;
			}
			if (l < r) {
				if (a[l].c != a[r].c) {
					ans += a[r].val;
				}
				a[l].val -= a[r].val;
				a[r].val = 0;
				r--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

