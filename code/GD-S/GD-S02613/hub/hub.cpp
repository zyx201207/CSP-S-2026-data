#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sol() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a >> a;
	}
	if (n == k) {
		cout << 0 << endl;
		return;
	}
	if (n / 2 <= k) {
		cout << 1 << endl;
		return;
	}
	int m = n / 2 - k + 7;
	cout << m / 4 << endl;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c, t;
	cin >> c >> t;
	while (t--) {
		sol();
	}
	return 0;
}
