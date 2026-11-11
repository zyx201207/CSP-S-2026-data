#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e17;

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);	
	
	int c, T; cin >> c >> T;
	while (T--) {
		int n; ll d; cin >> n >> d;
		vector<ll> x(n + 1); for (int i = 1; i <= n; i++) cin >> x[i];
		ll ans = 0;
		vector<ll> jum(n + 1), nxt(n + 1);
		
		int j = 1 + 1;
		for (int i = 1; i <= n; i++) {
			while (x[j] - x[i] <= d) j++;
			nxt[i] = j - 1;
		}
		
//		cout <<"nxt = "; for (int i = 1; i <= n; i++) cout << nxt[i] << ' '; cout << endl;
		vector<vector<ll>> f(n + 1, vector<ll> (n + 1, INF));
		
		for (int i = 1; i <= n; i++) f[i][i] = 0;
		
		for (int i = 1; i <= n; i++) {
			int cnt = 1, p = nxt[i], lp = i;
			for (; p < n; lp = p, p = nxt[p]) {
//				cout << "p : "<< p << ' ' << lp << endl;
				for (int j = lp + 1; j <= p; j++)
					f[i][j] = cnt;
				cnt++;
				if (lp == p) break;
			}
			for (int j = lp + 1; j <= n; j++) f[i][j] = cnt;
		}
		
//		for (int i = 1; i <= n; i++) {
//			for (int j = i + 1; j <= n; j++)
//				cout << f[i][j] << ' ';
//			cout << endl;
//		}
		for (int i = 1; i <= n; i++)
			for (int j = nxt[i] + 1; j <= n; j++) {
				int sum = 0;
				for (int k = i + 1; k < j; k++) {
					if (f[i][k] + f[k][j] == f[i][j]) {
						sum++;
						if (sum > 2) break;
					}
//						cout << f[i][k] << ' ' << f[k][j] <<' ' << f[i][j] << '\n'
//							 << i << ' ' << j <<' '<< k <<'\n' << '\n';
				}
				ans += (sum == 2);
//				if (sum == 2) cout << i << ' ' << j << endl;
			}
		cout << ans << '\n';
	}
	return 0;
} 
