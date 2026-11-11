#include <bits/stdc++.h>
using namespace std;

int n, m, x, a[500001], c[300001], r[300001];
vector <int> v;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	x = n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (c[a[j]] > 0) {
				int top;
				while (top != c[a[j]] && v.size()) {
					v.erase(v.end() - 1);
					top = v.back();
				}
				c[a[j]] = 0;
			} else v.push_back(a[j]);
			c[a[j]]++;
		}
		for (int k : v) r[k]++;
		memset(c, 0, sizeof(c));
		v.clear();
	}
	for (int i = 1; i <= m; i++) cout << r[i] << ' ';
	return 0;
}