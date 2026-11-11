#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N];
char c[N]; 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int ans = 0;
	int sum_ = 0;
	int finish = sum / 2;
	for (int i = 1; i <= n; ++i) {
		sum_ += a[i];
		if (sum_ >= finish) {
			finish = i;
			break;
		}
	}
	int l = 1, r = n, rhave = a[n];
	while (l <= finish && l < r) {
		int need = a[l];
		while (need) {
			if (c[r] == c[l]) {
				if (need < rhave) {
					rhave -= need;
					break;
				}
				else r--, need -= rhave, rhave = a[r];
			}
			else {
				if (need < rhave) {
					ans += need;
					rhave -= need;
					break;
				}
				else ans += rhave, need -= rhave, r--, rhave = a[r]; 
			}
		}
		l++;
	}
	cout << ans;
	return 0;
}

