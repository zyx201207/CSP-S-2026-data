#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, maxn = -INF, pre;
int a[200010];
bool f[200010];

int DFS (int cnt, int maxX, int now, int j) {
    if (cnt == 20) {
        return max(maxX, now);
    }
    for (int i = 1; i <= n; ++i) {
        if (!f[i] && j != i) {
            f[i] = 1;
            DFS(cnt + 1, maxX, now & a[i], j);
            f[i] = 0;
        }
    }
    return maxX;
}

int main() {
    //freopen("and.in", "r", stdin);
    //freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i == 1) pre = a[i];
        pre = (pre & a[i]);
        maxn = max(maxn, a[i]);
    }
    if (m == 1) {
        cout << maxn << '\n';
        return 0;
    }
    int ti = maxn;
    maxn = -INF;
    if (m == n) {
        cout << pre << '\n';
        return 0;
    }
    if (m == 2) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) maxn = max(maxn, (a[i] & a[j]));
            }
        }
        cout << maxn << '\n';
        return 0;
    }
    maxn = -INF;
    if (m == n - 1) {
        for (int i = 1; i <= n; ++i) maxn = max(maxn, (pre | a[i]));
        cout << maxn << '\n';
        return 0;
    }
    int ans = -INF;
    for (int i = 1; i <= n; ++i) {
        if (!f[i]) {
            f[i] = 1;
            ans = max(ans, DFS(1, a[i], a[i], i));
            f[i] = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
