#include <iostream>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
using namespace std;
typedef long long ll;
ll s[200010];
ll a[200010];
char c[200010];
int n;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    ll tot = 0;
    rep (i, 1, n) {
        cin >> a[i] >> c[i];
        tot += a[i];
        s[i] = tot;
    }
    int q = 1, p = n;
    ll l = 1, r = tot;
    ll ans = 0;
    while (true) {
        if (l >= r || q >= p) break;
        if (a[q] == a[p]) {
            if (c[p] != c[q]) ans += a[p];
            l += a[q];
            r -= a[p];
            q++;
            p--;
        }
        if (a[q] < a[p]) {
            if (c[p] != c[q]) ans += a[q];
            l += a[q];
            r -= a[q];
            a[p] -= a[q];
            q++;
        }
        if (a[q] > a[p]) {
            if (c[p] != c[q]) ans += a[p];
            l += a[p];
            r -= a[p];
            a[q] -= a[p];
            p--;
        }
    }
    cout << ans;
    return 0;
}
