#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1010;
int c, t, n, k;
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		cout << ceil((double)(n / 2.0 + 2.0 - k) / 4.0) << "\n";
		for (int i = 1; i < n; i++) cin >> k >> k;
	}
	return 0;
}
