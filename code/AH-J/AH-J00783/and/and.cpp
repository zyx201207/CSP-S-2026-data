#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, a[N], ans = 0;
bool vis[N];
void dfs(int dep, int sum) {
    if (dep == m) {
        ans = max(ans, sum);
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(dep + 1, sum & a[i]);
            vis[i] = 0;
        }
    }
}
signed main(void) {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(0, 1073741823);
    cout << ans;
    return 0;
}
