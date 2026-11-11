#include<bits/stdc++.h>

using namespace std;
bool ST;
#define ll long long
const int maxn = 2e6 + 5;
namespace subA{
	ll a[maxn];
	void solve() {
		ll n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		if (d <= a[2] - a[1]) {
			cout << "0\n";
			return;
		}
		ll k = d / (a[2] - a[1]);
		cout << max(0ll, n - (k * 2) + 1) << '\n';
	}
}

namespace all{
	ll a[maxn], l[maxn], r[maxn], cnt[maxn];
	void solve() {
		ll n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			cnt[i] = 0;
		}
		ll ans = 0, k = 1;
		for (int i = 1; i <= n; ++i) {
			l[i] = lower_bound(a + 1, a + 1 + n, a[i] - d) - a;
			if (l[i] == i) {
				k = i;
			}
			r[i] = upper_bound(a + 1, a + 1 + n, a[i] + d) - a - 1;
			ans += cnt[l[i] + 1];
			cnt[r[i]]++;
		}
		cout << ans << '\n';
	}
	
}

void coder() {
	int c, T;
	cin >> c >> T;
	while(T--) {
		if (c == 11 || c == 12) {
			subA::solve();
		} else {
			all::solve();
		}
	}
}


bool ED;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr << (fabs(&ST - &ED) / 1024.0 / 1024.0) << "MB\n";
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	coder();
	
	return 0;
}
