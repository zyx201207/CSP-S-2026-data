#include <iostream>
#define int long long
using namespace std;
int ans = 0, a[2005];
int n, m;
void dfs(int u, int sel, int sum) {
    if (u == n + 1) {
        if (sel == m) ans = max(sum, ans);
        return ;
    }
    dfs(u + 1, sel, sum);
    if (sel < m) dfs(u + 1, sel + 1, sum & a[u]);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int maxn = 0, whole = (1 << 31) - 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        whole &= a[i];
    }
    if (n <= 20) {
        dfs(1, 0, (1 << 32) - 1);
    } else if (n <= 2000) {
        if (m == 1) ans = maxn;
        else if (m == n) ans = whole;
        else {
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    ans = max(ans, a[i] & a[j]);
                }
            }
        }
    }
    cout << ans << endl;
} // 50pts?
