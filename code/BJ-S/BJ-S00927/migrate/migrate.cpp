#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10;
const int L = 21;
int c, t, n, mn, tot, p1[maxn], p2[maxn], f[maxn][L];
ll d, a[maxn];
void dfs(int u, int st, int ed) {
    if (st > mn) return; if (u == ed) ++tot;
    for (int i = min(f[u][0], ed); i > u; i--) dfs(i, st + 1, ed);
}
void dfs2(int u, int st, int ed) {
    if (st > mn) return; if (u == ed) ++tot;
    for (int i = min(f[u][0], ed); i > max(u, min(f[u][0], ed) - 3); i--) dfs(i, st + 1, ed);
}
int main() {
    ios::sync_with_stdio(false);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i], p1[i] = p2[i] = n + 1;
        for (int i = 1, j = 1; i <= n; i++) {
            while (j < n && a[j + 1] - a[i] <= d) ++j;
            f[i][0] = j;
        }
        if (n <= 9) {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++) {
                    tot = mn = 0; bool F = false;
                    for (int p = i; p < j; p = f[p][0]) {
                        ++mn;
                        if (p == f[p][0]) {F = true; break;}
                    } if (F) continue;
                    dfs(i, 0, j); if (tot == 2) ++ans;
                }
            cout << ans << '\n';
            continue;
        }
        if (c >= 11 && c <= 12) {
            int mx = f[1][0] - 1;
            cout << (mx <= 1 ? 0 : n - (mx << 1) + 1) << '\n';
            continue;
        }
        if (c >= 13 && c <= 14) {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                int p1 = f[i][0];
                if (p1 == i + 2) ans += f[p1 - 1][0] - p1;
                else if (p1 > i + 2) ans += f[p1 - 1][0] - f[p1 - 2][0];
            }
        }
        if (c >= 15 && c <= 18) {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++) {
                    tot = mn = 0; bool F = false;
                    for (int p = i; p < j; p = f[p][0]) {
                        ++mn;
                        if (p == f[p][0]) {F = true; break;}
                    } if (F) continue;
                    dfs2(i, 0, j); if (tot == 2) ++ans;
                }
            cout << ans << '\n';
            continue;
        }
        for (int j = 1; j < L; j++)
            for (int i = 1; i <= n; i++)
                f[i][j] = f[f[i][j - 1]][j - 1];
        for (int i = 1; i <= n; i++) if (f[i][0] > i + 1) {
            int u = f[i][0], v = f[i][0] - 1;
            for (int j = L - 1; ~j; j--) if (f[u][j] != f[v][j])
                u = f[u][j], v = f[v][j];
            if (f[u][0] == f[v][0]) p1[i] = f[u][0]; 
            else continue;
            if (f[i][0] > i + 2) {
                u = f[i][0], v = f[i][0] - 1; int w = f[i][0] - 2;
                for (int j = L - 1; ~j; j--) if (f[u][j] != f[v][j] || f[v][j] != f[w][j] || f[u][j] != f[w][j])
                    u = f[u][j], v = f[v][j], w = f[w][j];
                if (f[u][0] == f[v][0] && f[v][0] == f[w][0]) p2[i] = f[u][0];
            }
        } int mn = n + 1, mn2 = n + 1, mn3 = n + 1; ll ans = 0;
        for (int i = n; i >= 1; i--) {
            if (p1[i] < mn) mn2 = mn, mn = p1[i];
            else if (p1[i] < mn2) mn2 = p1[i];
            if (p2[i] < mn3) mn3 = p2[i];
            ans += min(mn3, mn2) - mn;
        } cout << ans << '\n';
    }
    return 0;
}