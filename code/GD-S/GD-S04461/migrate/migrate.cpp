// 16:04 看完题目。没什么思路。
// 16:38 太复杂了，拿个性质A就跑吧
// 16:53 又思考了一会，开始编码。好饿
// 17:11 完成。

#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int c;

int n;
int64_t d;
int64_t A[N];

namespace solve_a_11_12 {

void solve () {
	int64_t tmp = A[2] - A[1];
	int64_t k = (d) / tmp;
	if (k <= 1) cout << "0\n";
	else cout << max((int64_t)0, n - k * 2 + 1) << "\n";
}

}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
		}
		if (c == 12 || c == 11) {
			solve_a_11_12::solve();
		}
	}
}