#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
		}
		if ((n - k) % 4 == 0) {
			cout << (n - k) / 4 << '\n';
		} else {
			cout << (n - k) / 4 + 1 << '\n';
		}
	}
	return 0;
}
