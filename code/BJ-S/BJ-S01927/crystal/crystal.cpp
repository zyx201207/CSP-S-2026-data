#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m;
ll a[N];

ll ans2(ll d, ll x) {
    for (ll i = 1; i; i++) {
        if (2 * x == (2 + d * i) * (i + 1)) return i + 1;
        else if (2 * x < (2 + d * i) * (i + 1)) return -1ll;
    }
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    bool f1 = true, f2 = true;
    cin >> a[1];
    ll num1 = a[1], num2 = a[1], d;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        if (num1 != a[i] || f1 == false) f1 = false;
        num1 = a[i];
        if (d != a[i] - num2 && i >= 3) f2 = false;
        d = a[i] - num2;
        num2 = a[i];
    }
    if (f1 == true) {
        cout << n << endl;
        return 0;
    }
    else if (f2 == true) {
        ll x = m / d;
        if (ans2(d, x) != -1) cout << ans2(d, x) + 1 << endl;
        return 0;
    }
    return 0;
}
