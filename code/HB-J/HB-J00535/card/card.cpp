#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 5e5 + 10;

ll n, m, a[N];
map<ll, bool> mp;

void solve () {
    cin >> n >> m;
    vector <ll> v (m + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--) {
        if (!mp[a[i]]) {
            v[a[i]] = i;
            mp[a[i]] = true;
        }
    }

    for (int i = 1; i <= m; i++)
        cout << v[i] << " ";
}

int main () {
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);

    int T = 1; // cin >> T;
    while (T--) {
        solve ();
    }

    return 0;
}
