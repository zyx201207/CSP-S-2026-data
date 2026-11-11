#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool v[200005][32];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans = -1;
	for (int i = 31; i >= -1; --i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (a[j] & (1 << i)) {
				v[j][i] = true;
				++cnt;
			}
		}
		if (cnt >= m) {
			ans = -1;
			for (int j = 1; j <= n; ++j) {
				a[j] = (v[j][i] ? a[j] : 0);
				ans &= (v[j][i] ? a[j] : -1);
			}
		} else if(ans != -1) {
			cout << ans << endl;
			return 0;
		}
	}
}
