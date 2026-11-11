#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const ll inf = 1e18 + 10;

ll C, T;

void solve() {
    ll n, d;
    cin >>n >> d;
    vector<ll>a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (11 <= C && C <= 12) {
        ll diff = a[2] - a[1];
        ll reach = floor(1.0 * d / diff) + 1;
        if (reach < 3) {
            cout << 0 << endl;
            return ;
        }
        ll r = 2 * reach - 2;
        cout << max(n - r + 1, 0LL) << endl;
        return ;
    } 
    vector<ll>dp(n + 1, inf);
    vector<ll>cnt(n + 1, 0);
    ll ans = 0;
    for (ll st = 1; st <= n; st++) {
        dp[st] = 0;
        cnt[st] = 1;
        for (ll i = st + 1; i <= n; i++) {
            dp[i] = inf;
            cnt[i] = 0;
            ll x = lower_bound(a.begin() + st, a.end(), a[i] - d) - a.begin();
            ll mn = inf, mcnt = 0;
            for (ll j = x; j <= i - 1; j++) {
                if (mn > dp[j]) {
                    mn = dp[j];
                    mcnt = 0;
                }
                if (mn == dp[j]) {
                    mcnt += cnt[j];
                }
            }
            dp[i] = mn + 1;
            cnt[i] = mcnt;
            if (cnt[i] == 2) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> C >> T;
    while (T--) {
        solve();
    }
}