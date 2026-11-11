#include<bits/stdc++.h> 
using namespace std;
long long n, m, mid, ans, a[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		long long x = m, cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] > a[i]) {
				continue;
			}
			x = x - (a[i] - a[j]);
			cnt++;
			if (x < 0) {
				break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
