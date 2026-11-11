#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

ll n, m, p, o, cnt = 1;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    ll a[n], sum[n + 1] = {0};
    for (ll i = 0; i < n; ++i) {
        a[i] = read();
    } for (ll i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    p = sum[n] / n;
    sort(a, a + n);
    ll l = 0, r = n - 1;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (a[mid] == p) {
            o = mid;
            break;
        } if (a[mid] < p) {
            l = mid + 1;
        } else {
            r = mid;
        }
    } if (!o) {
        o = (abs(p - a[l]) < abs(p - a[r]) ? l : r);
    }
    l = o - 1;
    r = o + 1;
    while (m && l >= 0 && r <= n - 1) {
        if (abs(a[o] - a[l]) < abs(a[o] - a[r])) {
            if (m >= abs(a[o] - a[l])) {
                m -= abs(a[o] - a[l]);
                --l;
                ++cnt;
            } else {
                break;
            }
        } else {
            if (m >= abs(a[o] - a[r])) {
                m -= abs(a[o] - a[r]);
                ++r;
                ++cnt;
            } else {
                break;
            }
        }
    }
    write(cnt);
    return 0;
}
