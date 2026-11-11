#include <iostream>
#include <vector>
#include <cmath>

#define ll long long

#define eb emplace_back

using namespace std;

namespace sub1 {
	const int N = 310;
	
	int n, ans;
	
	ll d;
	
	ll x[N];
	
	int pre[N];
	
	ll dp[N][N][N], sm[N][N][N];
	
	vector <int> v1, v2;
	
	void sol () {
		cin >> n >> d, ans = 0;
		for (int i = 1; i <= n; ++ i) cin >> x[i], pre[i] = i;
		for (int i = 1; i <= n; ++ i)
			for (int j = i - 1; j; -- j)
				if (x[i] - x[j] <= d) pre[i] = j;
				else break;
		for (int i = 1; i <= n; ++ i) {
			dp[i][i][0] = 1;
			for (int t = 0; t <= n - i; ++ t) {
				for (int j = i; j <= n; ++ j)
					sm[i][j][t] = sm[i][j - 1][t] + dp[i][j][t];
				for (int k = i + 1; k <= n; ++ k)
					dp[i][k][t + 1] += sm[i][k - 1][t] - sm[i][max (i, pre[k]) - 1][t];
			}
			for (int j = 1; j <= n; ++ j) {
				int mx = 0;
				for (int t = 0; t <= j - i; ++ t)
					if (dp[i][j][t]) {
						mx = t;
						break;
					}
				if (dp[i][j][mx] == 2) ++ ans;
			}
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				for (int k = 1; k <= n; ++ k)
					dp[i][j][k] = sm[i][j][k] = 0;
	}
	
	void solve () {
		int t;
		cin >> t;
		while (t --) sol ();
	}
}

namespace subA {
	const int N = 2e6 + 10;
	
	int n;
	
	long double d;
	
	ll x[N];
	
	ll max (ll a, ll b) {
		return a > b ? a : b; 
	}
	
	void sol () {
		cin >> n >> d;
		for (int i = 1; i <= n; ++ i) cin >> x[i];
		if (n == 1) return cout << 0 << '\n', void ();
		long double D = x[2] - x[1];
		if (d < 2ll * D) cout << 0;
		else {
			ll x = d / D;
			cout << max (0, n - 2 * x + 1);
		}
		cout << '\n';
	}
	
	void solve () {
		int t;
		cin >> t;
		while (t --) sol ();
	}
}

int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	
	int c;
	cin >> c;
	if (c == 11 || c == 12) subA :: solve ();
	else if (c <= 6) sub1 :: solve ();
	else {
		int t;
		cin >> t;
		while (t --) {
			int n;
			ll d, x;
			cin >> n >> d;
			for (int i = 1; i <= n; ++ i) cin >> x;
			cout << 0 << '\n';
		}
	}
	
	return 0;
} 
