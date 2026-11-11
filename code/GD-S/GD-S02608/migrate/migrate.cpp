#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e6 + 10;

ll c, t, a[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	
	while (t--) {
		ll n, d, ans = 0; cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (a[i] + d + 1 == a[j]) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
