#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;

int c, t;

int n;
long long a[N];
long long d;
long long f[N][N], g[N][N];

void solve() {
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 1; j <= n; j++) f[i][j] = 4e18, g[i][j] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[j] - a[i] <= d) g[i][j] = f[i][j] = 1;
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(f[i][k] + f[k][j] < f[i][j]) g[i][j] = g[i][k] * g[k][j];
                else if(f[i][k] + f[k][j] == f[i][j]) g[i][j] += g[i][k] * g[k][j]; 
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            ans += (g[i][j] == 2);
        }
    }

    cout << ans << '\n';
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> c >> t;

    while(t--) {
        solve();
    }
}