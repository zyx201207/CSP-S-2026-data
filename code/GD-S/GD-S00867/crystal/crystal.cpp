#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, maxx, cnt = 1, tmp, g, a[500005];
bool f1, f2;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			f1 = 1;
		}
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			f2 = 1;
		}
	}
	sort(a + 1, a + n + 1);
	tmp = m;
	if (!f1) {
		for (int i = 1; i < n; i++) {
			tmp -= i;
			if (tmp >= 0) {
				cnt++;
			} else {
				break;
			}
		}
		cout << cnt;
		return 0;
	} else if (!f2) {
		g = a[2] - a[1];
		for (int i = 1; i < n; i++) {
			tmp -= i * g;
			if (tmp >= 0) {
				cnt++;
			} else {
				break;
			}
		}
		cout << cnt;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cnt = 1, tmp = m;
		for (int j = i - 1; j >= 1; j--) {
			tmp -= (a[i] - a[j]);
			if (tmp >= 0) {
				cnt++;
			} else {
				break;
			}
		}
		maxx = max(maxx, cnt);
	}
	cout << maxx;
	return 0;
}
