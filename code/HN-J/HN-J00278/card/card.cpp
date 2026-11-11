#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m, a[500005];
int v[500005], mp[300005];
int ans[300005];
int t;
void solve(int p) {
	t = 0;
	memset(mp, 0, sizeof mp);
	memset(v, 0, sizeof v);
	for(int i = p; i <= n; i++) {
		if(mp[a[i]] == 0) {
			t++;
			mp[a[i]] = t;
			v[t] = a[i];
		}
		else {
			int x = mp[a[i]];
			for(int i = x + 1; i <= t; i++) {
				mp[a[i]] = 0;
			}
			t = x;
			v[t] = a[i];
			mp[a[i]] = t;
		}
	}
	for(int i = 1; i <= t; i++) {
		ans[v[i]]++;
	}
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int x = n, p = 0;
	while(x--) {
		p++;
		solve(p);
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
