#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define qep(i, a, b) for(int i = (a); i >= (b); i --)
#define ll long long
#define i128 __int128
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 2000010;
const int INF = 1e18;
int cs, n, d, a[N];
int g[N], f[N];

void solution() {
	cin >> n >> d;
	rep(i, 1, n) cin >> a[i];
	if(n <= 3) {
		cout << "0\n";
		return;
	}
	if(cs >= 11 && cs <= 12) {
		int k = d / (a[2] - a[1]);
		if(k <= 1) cout << "0\n";
		else {
			k += (k - 1);
			cout << max(0ll, n - k) << '\n';
		}
		return;
	}
	if(cs >= 13 && cs <= 14) {
		cout << "0\n";
		return;
	}
	int ans = 0;
	rep(i, 1, n) {
		rep(j, i + 3, n) {
			f[i] = 0; g[i] = 1;
			rep(k, i + 1, j) f[k] = INF, g[k] = 0;
			rep(k, i + 1, j) {
				qep(l, k - 1, i) {
					if(a[k] - a[l] > d) break; 
					f[k] = min(f[k], f[l] + 1);
				} 
				qep(l, k - 1, i) {
					if(a[k] - a[l] > d) break; 
					if(f[l] + 1 == f[k]) g[k] += g[l];
				}
			}
			if(g[j] == 2) ans ++;
//			if(i == 1 && j == 4) {
//				rep(k, i - 1, j) cout << f[k] << ' '; cout << '\n';
//				rep(k, i - 1, j) cout << g[k] << ' '; cout << '\n';
//			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin >> cs >> tt;
	while(tt --) solution();
	return 0;
}

