#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int c, T;
const int N = 2e6 + 5;
ll a[N];

/*
0 2
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
*/

void solve() {
	if (c == 11 || c == 12 || c == 0) {
		int n;
		ll d;
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		ll del = a[2] - a[1];
		if (d <= del) {
			cout << "0\n";
		} else {
			ll k = d / del;
			ll ans = 0;
			if (2 * k - 1 > n - 1) cout << "0\n";
			else cout << n - 1 - (2 * k - 1) + 1 << "\n";
//			for (int i = 1; i <= n; i ++) {
//				ll x = n - i;
//				ll l = k + k - 1;
//				ll r = min((ll)n - i, k + k - 1);
//				if (l > x) continue;
//				else {
//					ans += (r - l + 1);
//				}
//			}
//			cout << ans << "\n";
		}
		return ;
	} 
	
	int n;
	ll d;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			vector<int> dis(n + 1);
			for (int msk = 0; msk < (1 << (j - i - 1)); msk ++) {
				int lst = i;
				int ok = 1;
				for (int l = 0; l < (j - i - 1); l ++) {
					if (msk >> l & 1) {
						if (a[i + l + 1] - a[lst] > d) {
							ok = 0;
							break;
						}
						else lst = i + l + 1;
					}
				}
				if (a[j] - a[lst] > d) ok = 0;
				if (ok) dis[__builtin_popcount(msk)] ++;
			}
//			cout << "#" << i <<" " <<j<<'\n';
			for (auto k : dis) {
				if (k != 0) {
					if (k == 2) ans ++;
					else break;
				}
//				cout << k << "\n";
			}
		}
	}
	cout << ans << "\n";
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> T;
	while (T --) solve();

	return 0;
}

