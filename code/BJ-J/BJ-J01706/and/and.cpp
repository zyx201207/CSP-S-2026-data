// and.cpp

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int a[N], f[2][N];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    // Here We Go!
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = -1e9;

    memset(f, 0xff, sizeof f);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, m); j++) {
            f[i%2][j] = max(f[(i-1)%2][j], f[(i-1)%2][j-1] & a[i]);
        }
        if (i >= m)
            ans = max(ans, f[i%2][m]);
    }


    cout << ans << endl;
}
