#include <bits/stdc++.h>

typedef long long ll;
const int MAXN = 20000000;

int n;
struct chuan {
    ll a;
    char ci;
} cc[MAXN];

ll juedui(ll a) {
    if (a > 0) return a;
    else return a * -1;
}

chuan t;
chuan b;

int main() {
    std::freopen("string.in", "r", stdin);
    std::freopen("string.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        ll a;
        char ci;

        std::cin >> a >> ci;

        cc[i] = {a, ci};
    }

    int ti = 0;
    int bi = n + 1;
    ll ans = 0;
    ll buffer = 0;
    int lock = 0;   // 1 lock top, 2 lock bottom

    while (ti <= n && bi >= 1) {
        if (lock != 1) t = cc[++ti];
        if (lock != 2) b = cc[--bi];

        int lent = t.a;
        int lenb = b.a;
        if (lock == 1) lent = buffer;
        if (lock == 2) lenb = buffer;

        if (t.ci != b.ci) {
            if (lent > lenb) {
                buffer = lent - lenb;
                ans += lenb;
                lock = 1;
            } else if (lent < lenb) {
                buffer = lenb - lent;
                ans += lent;
                lock = 2;
            } else {
                ans += lent;
                buffer = 0;
                lock = 0;
            }
        } else {
            if (lock == 1) {
                if (buffer == lenb) {
                    buffer = 0;
                    lock = 0;
                } else {
                    buffer = lenb - buffer;
                    if (buffer > 0) lock = 2;
                    else if (buffer < 0) lock = 1;
                    buffer = juedui(buffer);
                }
            }
            else if (lock == 2) {
                if (buffer == lent) {
                    buffer = 0;
                    lock = 0;
                } else {
                    buffer = lent - buffer;
                    if (buffer > 0) lock = 1;
                    else if (buffer < 0) lock = 2;
                    buffer = juedui(buffer);
                }
            } else {
                int tempBuffer = lent - lenb;
                if (tempBuffer > 0) {
                    lock = 1;
                    buffer = juedui(tempBuffer);
                }
                else if (tempBuffer < 0) {
                    lock = 2;
                    buffer = juedui(tempBuffer);
                }
            }
        }
    }

    std::cout << ans / 2;

    return 0;
}
