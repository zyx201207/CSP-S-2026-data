#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define bep(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
const ll maxn = 2e6 + 5;
ll c, t;
ll x[maxn];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		ll n, d;
		cin >> n >> d;
		rep(i, 1, n) {
			cin >> x[i];
		}
		ll ans = 0;
		rep(i, 4, n) {
			if(x[i] - x[i - 3] > d && x[i] - x[i - 1] < d && x[i - 1] - x[i - 2] < d) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
