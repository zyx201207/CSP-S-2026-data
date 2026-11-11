#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 2e6 + 10;
ll n, l, d, a[N];

inline void solve() {
	cout <<"#";
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	bool flag = true;
	d = a[2] - a[1];
	for (int i = 2; i < n; i++)
		if (a[i + 1] - a[i] != d) {
			flag = false;
			break;
		}
	if (flag) {
		if (l < 2*d) cout << 0 << endl;
		else {
			int t = l/d;
			t = t*2;
			ll ans = 0;
			for (int i = t; i <= n; i += 2) {
				ans += n - i + 1;
			}
			cout << ans << endl;
		}
	}
	return ;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _;
	cin >> _;
	cin >> _;
	while (_--) solve();
	return 0;
}

