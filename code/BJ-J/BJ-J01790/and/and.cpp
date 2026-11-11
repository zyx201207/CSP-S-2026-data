#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
bool st[200005];
int ans = INT_MAX;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		st[i] = true;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int base = 30; base >= 0; base --) {
		int cnt = 0;
		vector<int> curuse;
		for (int i = 1; i <= n; i ++) {
			if (!st[i])
				continue;
			if (a[i] & (1 << base)) {
				curuse.push_back(i);
				cnt ++;
			}
		}
		if (cnt < m)
			continue;
		memset(st, 0, sizeof st);
		for (const auto& v : curuse)
			st[v] = true;
	}
	for (int i = 1; i <= n; i ++)
		if (st[i])
			ans &= a[i];
	cout << ans << endl;
	return 0;
}