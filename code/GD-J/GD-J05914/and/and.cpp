#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2E5+5;
int n, m, a[MAXN];
int f[MAXN];
//f[]

signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		f[0] = a[i];
		for (int j = m; j >= 1; j --) {
			f[j] = max(f[j], f[j-1] & a[i]);
		}
	}
	
	cout << f[m];
	
	return 0; 
}
