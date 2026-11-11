#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int n, l = 0;
pair<int, char> a[200007];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if (n == 1) { cout << 0; return 0; }
	for (int i = 0; i < n; i++) {
		cin >> a[i].fi >> a[i].se;
		l += a[i].fi;
	}
	if (l == 1) { cout << 0; return 0; }
	
	if (n == 2) {
		cout<<min(a[0].fi, a[1].fi);
	} else {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i].fi;
		}
		cout << sum / 2;
	}
	
	return 0;
}
/*
3
2 a
2 b
1 c
*/
