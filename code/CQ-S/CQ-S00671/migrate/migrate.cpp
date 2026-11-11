#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using ll = long long;
constexpr int MAXN = 2e6 + 5;
int n, fa[MAXN];
ll d, a[MAXN], ans, res[MAXN][2], sum[MAXN];
void solve() {
    for (int i = n; i; --i) {
        res[i][0] = res[i][1] = 0, sum[i] = 0;
        int x = fa[i];
        int l = x, r = x;
        if (x - 2 > i) l = min(fa[x], max(x, fa[x - 2]));
        if (x - 1 > i) r = min(fa[x], fa[x - 1]);
        // cout << i << ' ' << x << ' ' << l << ' ' << r << '\n';
        if (x - 1 <= i || fa[x - 1] < fa[x]) res[i][0] += res[x][0], sum[i] += sum[x];
        if (x - 1 <= i || (fa[x - 1] < fa[x] - 1 || fa[x] - 1 <= x)) res[i][1] += res[x][1];
        // else if (fa[x - 1] < fa[x]) res[i][1] += res[fa[x]][1];
        if (x - 1 > i && fa[x - 1] == fa[x] && (x - 2 <= i || fa[x - 2] < fa[x])) res[i][1] += res[x][0];
        if (l < r) res[i][1] += r - l;
        res[i][0] += fa[x] - r;
        ans += res[i][1];
    }
}
int main() {
    IOS;
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T; cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = n, p = n; i; --i) {
            while (p > i && a[p] - a[i] > d) --p;
            fa[i] = p;
        }
        ans = 0;
        solve();
        cout << ans << '\n';
    }
    return 0;
}
/*
0 1
5 3
-2 -1 0 1 2

0 1
4 12
-10 -6 -2 10
*/