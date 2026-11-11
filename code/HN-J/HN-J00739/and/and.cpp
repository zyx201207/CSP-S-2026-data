#include <bits/stdc++.h>
using namespace std;

int n, m, ans;

vector <int> a[50], b;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		int w = 0;
		while (x) {
			if (x & 1) {
				a[w].push_back(i);
			}
			x >>= 1;
			w++;
		}
	}
	for (int i = 31; i >= 0; i--) {
		if (a[i].size() >= m) {
			if (b.size() == 0) {
				b = a[i], ans += (1 << i);
			} else {
				vector <int> c(0);
				for (int l = 0, r = 0; l < a[i].size(); l++) {
					while (b[r] < a[i][l]) r++;
					if (b[r] == a[i][l]) c.push_back(b[r++]);
				}
				if (c.size() >= m) b = c, ans += (1 << i);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
4 2
3 15 12 12
11 1111 1100 1100
1: 1 2
2: 1 2
3: 2 3 4
4: 2 3 4

5 3
31 3 1 15 7
11111 11 1 1111 111
0: 1 2 3 4 5
1: 
*/
