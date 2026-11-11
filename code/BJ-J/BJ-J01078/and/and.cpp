#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
//__builtin_popcount();
int n, m, a[200002], ans1, op = 1, g[22];
bool vis[200002];
void dfs(int x, int d) {
    if (d == m + 1) {
        ans1 = max(ans1, d);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(vis[i], d+1);
            vis[i] = false;
        }
    }
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        op |= __builtin_popcount(a[i]);

    }
    if (m == 1) {
        int ma = -1;
        for (int i = 1; i <= n; i++) {
            ma = max(ma, a[i]);
        }
        cout << ma;
    } else if (m == 2) {
        int ma = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ma = max(ma, a[i] & a[j]);
            }
        }
        cout << ma;
    } else if (m == n) {
        int ma = a[1];
        for (int i = 2; i <= n; i++) {
            ma &= a[i];
        }
        cout << ma;
    } else if (m == n - 1) {

    } else if (op == 1) {
        for (int i = 1; i <= n; i++) {
            g[int(log(a[i]))]++;
        }
        int ma = -1, k;
        for (int i = 1; i <= 20; i++) {
            if (ma < g[i]) {
                ma = g[i];
                k = i;
            }
        }
        if (ma >= m) {
            cout << (1 << k);
        } else {
            cout << 0;
        }
    } else if (n <= 20) {
        dfs(0xfffffff, 0);
        cout << ans1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

