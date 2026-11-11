#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define FILE(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
int main() {
	IOS; FILE("hub");
	int tid, T;
	cin >> tid >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
		}
		cout << ceil(1.0 * n / k / 2);
	}
	return 0;
}

