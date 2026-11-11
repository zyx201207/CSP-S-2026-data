#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int M = 1e3+5;

int c, n, m, d, q;
int w[M];
int a[M][M], t[M][M], k[505];
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= c; i++) {
        int aa, b;
        cin >> aa >> b;
        int tt, l;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k[i]; j++) {
                if (a[i][j] == aa) tt = t[i][j]; 
                if (a[i][j] == b) l = t[i][j]; 
            }
        }
        cout << w[aa] + w[b] + tt + l << '\n';
    }
    return 0;
}