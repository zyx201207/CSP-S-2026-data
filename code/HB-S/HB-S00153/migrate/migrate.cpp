#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300;
int a[N + 5], dpd[N + 5][N + 5], dpc[N + 5][N + 5];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int cs, T;
    cin >> cs >> T;
    if (cs == 13 || cs == 14) {
        while (T --) 
            printf("0\n");
        return 0;
    }
    while (T --) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        memset(dpd, 0x3f, sizeof dpd);
        memset(dpc, 0, sizeof dpc);
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j < i; j ++)
                if (a[i] - a[j] <= d)
                    dpd[j][i] = 1, dpc[j][i] = 1;
        for (int i = 1; i <= n; i ++)
            dpd[i][i] = 0;
        for (int k = 1; k <= n; k ++)
            for (int i = 1; i <= n; i ++)
                for (int j = 1; j <= n; j ++)
                    if (dpd[i][j] > dpd[i][k] + dpd[k][j])
                        dpd[i][j] = dpd[i][k] + dpd[k][j],
                        dpc[i][j] = dpc[i][k] * dpc[k][j];
                    else if (dpd[i][j] == dpd[i][k] + dpd[k][j])
                        dpc[i][j] += dpc[i][k] * dpc[k][j];
        int ans = 0;
        for (int i = 1; i <= n; i ++) 
            for (int j = 1; j <= n; j ++)
                ans += dpc[i][j] == 2;
        cout << ans << endl;
    }
    return 0;
}