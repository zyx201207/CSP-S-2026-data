#include <bits/stdc++.h>

#define ll long long

#define fileio(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout);

using namespace std;

const int maxn = 2e6 + 15;
const int maxn10 = 5000;

int n;
ll d;
ll x[maxn];
int dp[505][505];
int dmin[505];

void solve10() {
	cin >> n >> d;

	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}

	int ans = 0;

	for(int l = 1; l <= n; l++) {
		for(int r = 1; r <= n; r++) {
			dmin[r] = 111111;
		}
		for(int t = 0; t <= n; t++) {
			for(int r = 1; r <= n; r++) {
				dp[t][r] = 0;
			}
		}
		dp[0][l] = 1;
		for(int t = 1; t <= n; t++) {
			for(int r = l + 1; r <= n; r++) {
				for(int b = r - 1; b >= l; b--) {
					if(x[r] - x[b] > d) {
						break;
					}
					
					dp[t][r] += dp[t - 1][b];
				}
			}
		}
		for(int t = 1; t <= n; t++) {
			for(int r = l + 1; r <= n; r++) {
				if(dp[t][r]) {
					dmin[r] = min(dmin[r], t);
				}
			}
		}
		for(int r = l + 1; r <= n; r++) {
			if(dmin[r] == 111111) continue;
			
			if(dp[dmin[r]][r] == 2) {
				ans++;
			}
		}
	}
	
	cout << ans << '\n';
}

void solve1518() {

}

void solve1314() {
	int n, d;
	cin >> n >> d;
	
	
}

int main() {
	fileio("migrate")
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int c, t;
	cin >> c >> t;

	while(t--) {
		solve10();
	}

	return 0;
}
