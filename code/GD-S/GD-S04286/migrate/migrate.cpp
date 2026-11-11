#include <bits/stdc++.h>
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define pre(i, s, t) for (int i = s; i >= t; i--)
using namespace std;
const int N = 5005;
long long cs, n, d, a[N];
int dist[N][N], f[N][N];
struct SGT {
    #define ls u << 1
    #define rs u << 1 | 1
    #define mid (((l) + (r)) >> 1)
    int t[N << 2];
    void clr(int u, int l, int r) {
        t[u] = 0;
        if (l == r) return;
        clr(ls, l, mid), clr(rs, mid + 1, r);
    }
    void upd(int u, int l, int r, int p, int d) {
        if (l == r) return t[u] = min(3, t[u] + d), void();
        if (p <= mid) upd(ls, l, mid, p, d);
        else upd(rs, mid + 1, r, p, d);
        t[u] = t[ls] + t[rs];
    }
    int qry(int u, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return t[u];
        if (qr <= mid) return qry(ls, l, mid, ql, qr);
        if (ql > mid) return qry(rs, mid + 1, r, ql, qr);
        return min(3, qry(ls, l, mid, ql, qr) + qry(rs, mid + 1, r, ql, qr));
    }
} tr[N];
inline void sol() {
    // cout << "-------------------------\n";
    cin >> n >> d;
    rep(i, 1, n) cin >> a[i], tr[i].clr(1, 1, n);
    int p = 1, res = 0;
    rep(i, 1, n) rep(j, 1, n) dist[i][j] = 2e9, f[i][j] = 0;
    dist[1][1] = 0, f[1][1] = 1;
    tr[1].upd(1, 1, n, 1, f[1][1]);
    // cout << "****" << tr[1].qry(1, 1, n, 1, 1) << '\n';
    rep(i, 2, n) {
        while (p < i && a[i] - a[p] > d) p++;
        dist[i][i] = 0, f[i][i] = 1;
        rep(j, 1, i - 1) dist[j][i] = dist[j][max(p, j)] + 1;
        // rep(j, 1, i) sf[j] = min(sf[j], dist[j][i]), cout << sf[j] << ' ';
        // cout << '\n';
        rep(j, 1, i - 1) {
            int x = lower_bound(dist[j] + max(p, j), dist[j] + i + 1, dist[j][i] - 1) - dist[j],
                y = upper_bound(dist[j] + max(p, j), dist[j] + i + 1, dist[j][i] - 1) - dist[j] - 1;
            if (x <= y) f[j][i] = tr[j].qry(1, 1, n, x, y);
            // if (j == 1 && i == 5) cout << j << ' ' << x << ' ' << y << ' ' << tr[j].qry(1, 1, n, x, y) << '\n';
            tr[j].upd(1, 1, n, i, f[j][i]);
        }
        tr[i].upd(1, 1, n, i, f[i][i]);
        // rep(j, 1, i - 1) rep(k, max(p, j), i - 1) {
        //     int nw = dist[k][j] + 1;
        //     if (dist[i][j] > nw) dist[i][j] = nw, f[i][j] = f[k][j];
        //     else if (dist[i][j] == nw) f[i][j] = min(3ll, f[i][j] + f[k][j]);
        // }
    }
    // rep(i, 1, n) rep(j, 1, i - 1) cout << dist[j][i] << ' ' << j << "->" << i << '\n';
    rep(i, 1, n) rep(j, 1, i - 1) res += (f[j][i] == 2);//, cout << f[j][i] << ' ' << j << "->" << i << '\n';
    cout << res << '\n';
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T; cin >> cs >> T;
    while (T--) sol();
    return 0;
}
/*
0 1
6 3
0 1 2 3 4 7
*/