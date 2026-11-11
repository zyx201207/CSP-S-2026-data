#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010], ans = -1, num, mx = -1;
bool flag = 1;
vector <int> null;
void dfs (int id, int sum, int sz, vector <int> v) {
	if (sz == m) {
		ans = max (ans, sum);
		return ;
	}
	if (id > n) return ;
	v.push_back (a[id]);
	sz ++;
	int ssum = sum;
	if (sz == 1) ssum = a[id];
	else ssum &= a[id];
	dfs (id + 1, ssum, sz, v);
	v.pop_back ();
	sz --;
	dfs (id + 1, sum, sz, v);
}
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (i == 1) num = a[i];
		else num &= a[i];
		if (a[i] != i - 1) flag = 0;
		mx = max (mx, a[i]);
	}
	if (m == n) {
		cout << num;
		return 0;
	}
	if (flag) {
		cout << n - m;
		return 0;
	}
	if (m == 1) {
		cout << mx;
		return 0;
	}
	if (m == 2) {
		int ss = -1;
		for (int i = 1; i <= n; i ++) 
			for (int j = i + 1; j <= n; j ++) 
				ss = max (ss, a[i] & a[j]);
		cout << ss;
		return 0;
	}
	dfs (1, 0, 0, null);
	cout << ans;
	return 0;
}
//60pts
