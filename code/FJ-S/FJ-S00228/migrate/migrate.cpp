#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MN = 500005;
ll ns[MN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while (t --) {
		ll n, d, x, nd, f = 0;
		cin >> n >> d;
//		if (c >= 11 && c <= 12) {
//			int nd;
//			while (n --) {
//				cin >> x;
//				if (f) nd = x - f;
//			}
//			cout << (d / nd)
//		}
		vector<ll> ds(n);
		for (int i = 0; i < n; i ++) {
			cin >> x;
			if (!i) f = x, ds[0] = 0;
			else ds[i] = x - f;
		}
//		for (int i = 0; i < n - 1; i ++) {
//			for (int j = i + 1; j < n; j ++) {
//				if (ds[j] - ds[i] == )
//			}
//		}
		cout << 0 << endl;
	}
}
 
