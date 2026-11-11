#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
pair<long long, char> a[N];
long long ans, n;

int main () {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i].first >> a[i].second;
	}
	int l = 1, r = n;
	while (l <= r) {
		if (a[l].second != a[r].second) {
			if (a[l].first < a[r].first) {
				ans += a[l].first;
				a[r].first -= a[l].first;
				l ++;
			} else if (a[l].first > a[r].first) {
				ans += a[r].first;
				a[l].first -= a[r].first;
				r --;
			} else {
				ans += a[l].first;
				l ++;
				r --;
			}
		} else {
			if (a[l].first > a[r].first) {
				a[l].first -= a[r].first;
				r --;
			} else if (a[l].first < a[r].first) {
				a[r].first -= a[l].first;
				l ++;
			} else {
				l ++;
				r --;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
