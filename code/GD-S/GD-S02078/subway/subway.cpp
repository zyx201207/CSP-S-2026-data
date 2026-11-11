#include <bits/stdc++.h>
using namespace std;

struct node {
	int top;
	vector <int> h;
	vector <int> t;
}a[510];
int c, n, m, d, q, w[500010];
int b[510][510];
vector <int> be[500010];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k, a; i <= n; i++) {
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> a >> a;
		} 
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << w[l] + w[r] << "\n";
	}
	return 0;
} 
