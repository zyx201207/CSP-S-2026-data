#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		int n, k, u, v;
		cin >> n >> k;
		for (int i = 1; i < n; i++)
			cin >> u >> v;
		cout << k - 1 << '\n';
	}
	return 0;
}

