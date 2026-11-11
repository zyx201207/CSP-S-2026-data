#include <bits/stdc++.h>
using namespace std;
struct zhi {
	int q, p;
};
int n, m, a[500010]; zhi le[500010];
int ef(int x, int l, int r) {
	int mid, pos = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (le[mid].q == le[x].q) {
			pos = max(pos, x);
			l = mid + 1;
		} else {
			int y = max(ef(x, mid + 1, r), ef(x, l, mid - 1));
			pos = max(y, pos);
		}
	} return pos;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x; le[i].q = x;
		le[i].p = i + 1;
		if (i == n) le[i].p = 0;
	}
	for (int i = 1; i <= n; i++) {
		int l = i, r = n;
		for (int j = i; j <= n; j++) {
			int pos = j, pos1 = ef(j, j + 1, n);
			if (pos1 == -1) continue;
			else le[pos - 1].p = pos1;
		}
		int pos = 1;
		while (le[pos].p != 0) {
			a[le[pos].q]++;
			pos = le[pos].p;
		}  
	}
	for (int i = 1; i <= m; i++) cout << a[i] << ' ';
	return 0;
}
