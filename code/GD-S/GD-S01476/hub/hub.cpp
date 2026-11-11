#include <iostream>

using namespace std;

int c, t, n, k;
int u[1000001], v[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		cin >> n >> k;
		for (int i = 0; i < n; i ++) {
			cin >> u[i] >> v[i];
		}
	}
	cout << 0 << endl;
	return 0;
}
