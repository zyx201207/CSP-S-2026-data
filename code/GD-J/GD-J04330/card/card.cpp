#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], ans[M], flag = 1, last[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		last[a[i]] = i;
		if (a[i - 1] > a[i]) {
			flag = 0;
		}
	}
	if (flag == 1) {
		for (int i = 1; i <= m; i++) {
			cout << last[i] << " ";
		}
	}
	else if (m == 1) {
		cout << n;
	}
	else if (m == 2) {
		int pos = 0;
		for (int i = 1; i <= 2; i++) {
			if (last[i] == n) {
				ans[i] = n;
				pos = i;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] != pos) {
				ans[a[i]]++;
			}
		}
		cout << ans[1] << " " << ans[2];
	}
	return 0;
}
