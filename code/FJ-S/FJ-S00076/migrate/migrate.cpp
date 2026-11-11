#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

//#define DEBUG
#ifdef DEBUG
#define debug(fmt,...) printf(fmt,##__VA_ARGS__)
#else
#define debug(fmt,...)
#endif

/*
0 5
4 2
1 3 5 7
4 3
1 3 5 6
4 6
2 4 6 8
4 4
2 4 6 8
5 9
2 6 10 14 18

*/

void solve() {
	ll ans = -1;
	ll n,d;
	cin >> n >> d;
	vector <ll> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (i >= 2) {
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
				ans = 0; 
			}
		}
	}
	if (ans == 0) {
		cout << 0 << endl;
		return;
	}
	if (d >= 2 * (a[1] - a[0]) && d < 3 * (a[1] - a[0])) {
		cout << n - 3 << endl;
	} else {
		cout << 0 << endl;
	}
	
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate4.in","r",stdin);
	int c,t;
	cin >> c >> t;
	while (t--) {
		solve();
	} 
	
	return 0;
} 
