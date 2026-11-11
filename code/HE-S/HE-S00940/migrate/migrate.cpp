//Oct31==Dec25?
#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 5010;

int c, T, n, ans;
ll d;
ll x[N], f[N][N], g[N][N];


int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d; ans = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) g[i][j] = 0, f[i][j] = 2e18 + 1;
		for (int i = 1; i <= n; ++i) 
			cin >> x[i], g[i][i] = 1, f[i][i] = 0;
		for (int i = 1; i <= n; ++i) 
			for (int j = i + 1; j <= n; ++j) 
				for (int k = i; k < j; ++k) {
					if (x[j] - x[k] > d) continue;
					if (f[i][k] + 1 == f[i][j]) g[i][j] += g[i][k];
					if (f[i][k] + 1 < f[i][j]) f[i][j] = f[i][k] + 1, g[i][j] = g[i][k];
				}	
		for (int i = 1; i <= n; ++i) 
			for (int j = i + 1; j <= n; ++j) if (g[i][j] == 2) ans++;
		cout << ans << '\n';
	}
	return 0;
}
