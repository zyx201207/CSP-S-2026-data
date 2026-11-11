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

int c, n, d;
ll m, q;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    ll w[m], sum = 0;
    for (int i = 0; i < m; ++i) {
        w[i] = read();
        sum += w[i];
    }
    cout << sum << sum / 2;
    return 0;
}
