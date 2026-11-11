#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, a[500010], cnt[300010], ans[300010];
bool A = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i - 1] > a[i]) A = false;
    }

    if (A) {
        for (ll i = 1; i <= n; i++) 
            if (a[i] != a[i - 1]) ans[a[i - 1]] = i - 1;
        ans[a[n]] = n;
    } else {
        for (ll i = 1; i <= n; i++) {
            stack<ll> s;
            for (ll j = 1; j <= m; j++) cnt[j] = 0;
            for (ll j = i; j <= n; j++) {
                if (cnt[a[j]] > 0) 
                    while (!s.empty()) {
                        ll y = s.top(); s.pop();
                        cnt[y]--;
                        if (a[j] == y) break;
                    }
                s.push(a[j]);
                cnt[a[j]]++;
            }
            while (!s.empty()) ans[s.top()]++, s.pop();
        }
    }

    for (ll i = 1; i <= m; i++) cout << ans[i] << ' ';
    
    return 0;
}

// 100 + 100 + 100 + 52 EOF
