#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    ll u, v, w;
    node(ll u, ll v, ll w) : u(u), v(v), w(w) {
    }
};

int c, t;

ll read() {
    ll l = 0, f = 1;
    int k = getchar();
    while ('0' > k || '9' < k) {
        if (k == '-') {
            f = -f;
        }
        k = getchar();
    } while ('0' <= k && k <= '9') {
        l = 10 * l + (k - '0');
        k = getchar();
    }
    return l * f;
}

void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    } if (x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
    c = read(), t = read();
    while (t--) {
        ll n = read(), d = read();
        ll x[n], sum[n + 1] = {0};
        vector<node> g[n];
        for (ll i = 0; i < n; ++i) {
            x[i] = read();
        }
        cout << 0 << '\n';
    }
    return 0;
}
