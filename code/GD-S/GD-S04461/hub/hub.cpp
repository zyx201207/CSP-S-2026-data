// 17:22 就拿个性质A。已经不想思考了
// 17:36 完成。

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c;
int n, k;
namespace solve_a_13_14 {

void solve () {
	int a;
	for (int i = 1; i <= n * 2 - 2; i++) {
		cin >> a;
	}
	if (k == 1) {
		n /= 2; n -= k;
		cout << (n + 1) / 2 + 1 << "\n";
	}
	else if (k < n / 2) {
		n /= 2; n -= k;
		cout << (n + 3) / 4 + 1 << "\n";
	}
	else if (k < n) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}

}

}
int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		if (c == 13 || c == 14) {
			solve_a_13_14::solve();
		}
	}
}