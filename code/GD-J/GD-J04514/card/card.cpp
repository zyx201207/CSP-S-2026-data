#include <bits/stdc++.h>
using namespace std;
int n, m, a[500007], table[500007], z, ans[500007];
map<int, int> mp;

void del(int p) {
	for (int i = p; i < z-1; i++) {
		table[i] = 0;
	}
	z = z-p;
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int j = 1; j <= n; j++) {
		memset(table, 0, sizeof(table));
		mp.clear();
		z = 0;
		for (int i = j; i <= n; i++) {
			auto c = a[i];
			if (mp[c] == 0) {
				table[z++] = c;
				mp[c] = z;
			} else {
				del(mp[c]);
			}
//			for (int k = 0; k < z; k++) cout << table[k]<< ' ';
//			cout << '\n';
		}
		for (int i = 0; i < z; i++) {
			ans[table[i]]++;
		}
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	
	return 0;
}
