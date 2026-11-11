#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, a[200010], ans;
bool book[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    for (ll i = 1; i <= n; i++) cin >> a[i];

    for (ll k = 31; k >= 0; k--) {
        ll cnt = 0;
        for (ll i = 1; i <= n; i++)
            if (!book[i] && ((a[i] >> k) & 1)) cnt++;
        if (cnt >= m) {
            ans += (1ll << k);
            for (ll i = 1; i <= n; i++) 
                if (!((a[i] >> k) & 1)) book[i] = true;
        }
    }

    cout << ans;

    return 0;
}
