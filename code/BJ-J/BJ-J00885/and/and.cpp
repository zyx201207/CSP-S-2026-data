#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int a[200000], n, m, ans;
void dfs(int p = 0, int q = 0, int sum = INT_MAX) {
    if (p == n) {
        if (q == m) ans = max(ans, sum);
        return;
    }
    if (q < m) dfs(p + 1, q + 1, sum & a[p]);
    dfs(p + 1, q, sum);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (m == 1) ans = max(ans, a[i]);
    }
    bool fl = false;
    for (int i = 0; i < n; i++) {
        if (__builtin_popcount(a[i] + 1) != 1) {
            fl = true;
            break;
        }
    }
    if (!fl) nth_element(a, a + n, a + m - 1), ans = max(ans, a[m - 1]);
    if (m > 1) dfs();
    cout << ans;
}
