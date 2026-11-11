#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m; cin >> n >> m;
    vector<ll> a;
    a.resize(n);
    for (ll i = 0 ; i < n ; i++) cin >> a[i];
    sort(a.begin(), a.end());

    queue<ll> q; q.push(a[0]);
    ll cost = 0, ans = 1;
    for (ll i = 1 ; i < n ; i++) {
        cost += (a[i] - q.back()) * q.size();
        while (cost > m) {
            cost -= a[i] - q.front();
            q.pop();
        }
        q.push(a[i]);
        if (q.size() > ans) ans = q.size();
    }
    cout << ans << endl;
    return 0;
}
