#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010];
bool flag = 1;
int v[500010], r, mp[300010];
int mpp[300010], ans[300010];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) flag = 0;
		mp[a[i]] ++;
	} 
	if (flag) {
		for (int i = 1; i <= m; i ++) {
			mp[i] += mp[i - 1];
			cout << mp[i] << ' ';
		}			
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		memset (v, 0, sizeof (v));
		memset (mpp, 0, sizeof (mpp));
		r = 0;
		for (int j = i; j <= n; j ++) {
			if (mpp[a[j]] == 0) {
				v[++ r] = a[j];
				mpp[a[j]] = r;
			} else {
				for (int k = mpp[a[j]] + 1; k <= r; k ++) mpp[v[k]] = 0;
				r = mpp[a[j]];
			}
		}
		for (int j = 1; j <= r; j ++) 
			ans[v[j]] ++;
	}
	for (int i = 1; i <= m; i ++) 
		cout << ans[i] << ' '; 
	return 0;
}
//40pts
