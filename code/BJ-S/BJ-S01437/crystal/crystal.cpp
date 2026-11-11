#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5e5;
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

inline void wrt(int x) {
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
ll m;
ll a[N + 3];
ll s[N + 3];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int r = 1, l = 1; r <= n; r++) {
        while (a[r] * (r - l + 1) - (s[r] - s[l - 1]) > m)
            l++;
        ans = max(ans, r - l + 1);
    }
    wrt(ans), pc('\n');
    flush();
    return 0;
}
