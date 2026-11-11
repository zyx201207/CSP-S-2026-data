#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int, int>

const int N = 510, M = 5e5 + 10;

vector<ll> a[N], t[N];

int _, n, m, D, q, w[M], K[N], mx = 0, tot = 1;
bool mp[N][M];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> _ >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
			mp[i][x] = true;
			mx = max(mx, x);
		}
	}
	ll mn = 2e18;
	if(n == 2) {
		for(int i = 1; i <= mx; i++) {
			if(mp[1][i] && mp[2][i]) {
				mn = min(mn, t[1][i] + t[2][i]);
			}
		}
	}
	while(q--) {
		int S, T;
		cin >> S >> T;
		ll ans = w[S] + w[T];
		if(n == 1) {
			cout << ans << '\n';
		} else if(n == 2) {
			if((mp[1][S] && mp[1][T]) || (mp[2][S] && mp[2][T])) {
				cout << ans << '\n';
			} else {
				cout << ans + mn << '\n';
			}
		}
	}
	return 0;
}
