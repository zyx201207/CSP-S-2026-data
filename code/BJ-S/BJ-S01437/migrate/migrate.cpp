#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6;
const ll mod = 990811293722049451;
const int BUFSIZE = 1 << 20;
char ibuf[BUFSIZE], *p1 = ibuf, *p2 = ibuf;
char obuf[BUFSIZE], *p3 = obuf;

#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, BUFSIZE, stdin), p1 == p2) ? EOF : *p1++)
#define pc(x) (p3 - obuf < BUFSIZE ? *p3++ = (x) : (fwrite(obuf, 1, BUFSIZE, stdout), p3 = obuf, *p3++ = (x)))

inline void flush() {
    if (p3 != obuf)
        fwrite(obuf, 1, p3 - obuf, stdout);
}

inline ll read() {
    ll x = 0, w = 1;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-')
            w = -1;
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = gc();
    }
    return x * w;
}

inline void wrt(ll x) {
    if (x < 0) {
        pc('-');
        x = -x;
    }
    char stk[20], tp = 0;
    do {
        stk[tp++] = x % 10 + 48;
        x /= 10;
    } while (x);
    while (tp--)
        pc(stk[tp]);
}

int n;
ll d;
ll a[N + 3];
struct node {
    ll f;
    int d;
} F[N + 3];
node operator +(node x, node y) {
    if (x.d == y.d) {
        ((x.f += y.f) >= mod) && (x.f -= mod);
        return x;
    }
    if (x.d < y.d)
        return x;
    return y;
}
node operator +(node x, int y) {
    return {x.f, x.d + y};
}
ll cnt[N + 3];

inline void slv() {
    n = read(), d = read();
    bool f = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (i >= 3)
            f &= (a[i] - a[i - 1] == a[2] - a[1]);
    }
    ll ans = 0;
    if (f) {
        int u = 1;
        F[u] = {1, 0};
        cnt[0] = 1;
        int mn = 0;
        for (int v = u + 1, p = u; v <= n; v++) {
            while (p < v && a[v] - a[p] > d) {
                ((cnt[F[p].d] -= F[p].f) < 0) && (cnt[F[p].d] += mod);
                p++;
            }
            if (p == v)
                break;
            while (!cnt[mn])
                mn++;
            F[v] = {cnt[mn], mn + 1};
            ((cnt[mn + 1] += cnt[mn]) >= mod) && (cnt[mn + 1] -= mod);
            ans += (cnt[mn] == 2) * (n - v + 1);
        }
        for (int i = mn; i <= n; i++)
            cnt[i] = 0;
    } else {
        for (int u = 1; u <= n; u++) {
            F[u] = {1, 0};
            cnt[0] = 1;
            int mn = 0;
            for (int v = u + 1, p = u; v <= n; v++) {
                while (p < v && a[v] - a[p] > d) {
                    ((cnt[F[p].d] -= F[p].f) < 0) && (cnt[F[p].d] += mod);
                    p++;
                }
                if (p == v)
                    break;
                while (!cnt[mn])
                    mn++;
                F[v] = {cnt[mn], mn + 1};
                ((cnt[mn + 1] += cnt[mn]) >= mod) && (cnt[mn + 1] -= mod);
                ans += cnt[mn] == 2;
            }
            for (int i = mn; i <= n - u + 1; i++)
                cnt[i] = 0;
        }
    }
    wrt(ans), pc('\n');
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    read();
    int t = read();
    while (t--)
        slv();
    flush();
    return 0;
}
