#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 200010;
const int INF = 0x3f3f3f3f;

int n, m;
int a[MAXN];

int dfsAns = -INF;

int k[MAXN];

void dfs(int x, int start, int v, int cnt) {
    if (n - start + 1 < cnt) return;
    if (x > m) {
        dfsAns = max(dfsAns, v);
        return;
    }
    for (int i = start; i <= n; i++) {
        if (x == 1) dfs(x + 1, i + 1, a[i], cnt - 1);
        else dfs(x + 1, i + 1, a[i] & v, cnt - 1);
    }
}

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (m == 1) { // Point 6
        int ans = -INF;
        for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
        cout << ans << '\n';
    }
    else if (m == n) { // Point 7
        int ans = a[1];
        for (int i = 2; i <= n; i++) ans = ans & a[i];
        cout << ans << '\n';
    }
    else if (m == 2) { // Point 8 ~ 10
        int ans = -INF;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans << '\n';
    }
    else if (n <= 20) { // Point 1 ~ 5
        dfs(1, 1, 0, m);
        cout << dfsAns << '\n';
    }
    else { // A
        for (int i = 1; i <= n; i++) {
            for (int lg = 1; lg <= 30; lg++) {
                if ((1 << lg) - 1 == a[i]) {
                    k[i] = lg;
                    break;
                }
            }
        }
        sort(k + 1, k + 1 + n, greater<int>());
        cout << (1 << k[m]) - 1 << '\n';
    }
    return 0;
}
