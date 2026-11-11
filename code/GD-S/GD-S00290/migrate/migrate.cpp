#include <bits/stdc++.h>
#define rep(i,j,k) for (int i = (j); i <= (k); i++)
#define rrep(i,j,k) for (int i = (j); i >= (k); i--)
#define orep(i,j,k) for (int i = (j); i < (k); i++)
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <class T>
using vec = vector<T>;
using veci = vec<int>;

void solve() {
    int n;
    ll d;
    cin >> n >> d;
    vec<ll> a(n+1);
    rep(i,1 , n) cin >> a[i];
    veci nxt(n+1);
    nxt[n] = n;
    rrep(i, n-1, 1) {
        nxt[i] = nxt[i+1];
        while (a[nxt[i]] - a[i] > d) nxt[i]--;
    }
    vec<array<int, 4>> c(n+1);
    rrep(p, n, 1) {
        rep(msk, 0, 3) {
            int f = p - (msk >> 1);
            int s = f - (msk & 1);
            if (s <= 0) continue;
            if (nxt[p] == p) continue;
            f = nxt[f], s = nxt[s];
            c[p][msk] += (f - p) - (s - p);
            int np = nxt[p];
            if (f < np-1) s = f, f = np-1;
            else if (s < np-1) s = np-1;
            if (s < np-2) s = np-2;
            c[p][msk] += c[np][(np - f) * 2 + (f - s)];
        }
    }
    ll ans = 0;
    rrep(i, n, 1) {
        if (nxt[i] == i) continue;
        int f = nxt[i] - 1, s = nxt[i] - 2, p = nxt[i];
        if (s < i) s = f;
        ans += c[p][(p - f) * 2 + (f - s)];
    }
    cout << ans << '\n';
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, T;
    cin >> c >> T;
    while (T--) solve();
}