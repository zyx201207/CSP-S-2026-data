#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;

    ll i = 0, j = 0, cost = 0, maxlen = 1;
    while (j < n) {
        if (cost <= m) {
            maxlen = max(maxlen, j - i + 1);
            j++;
            cost += (a[j] - a[j - 1]) * (j - i);
        } else {
            cost -= a [j] - a[i];
            i++;
        }
        // if (i == j) cout << cost << endl;
    }

    // cout << i << ' ' << j << ' ' << cost << '\n';

    cout << maxlen << '\n';

    return 0;
}