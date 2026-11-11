/*
Find the least time of each trip.
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll c, n, m, d, q, lst;
ll w[500010];
ll k[510];
vector<ll> s[500010];

ll dfs(ll x, ll y, ll depth){
    if(s[x].empty()) return 0;

    if(x == y) return depth;

    ll ans = 0;

    for(auto u : s[x]){
        if(u != lst) ans += dfs(u, y, depth);
    }

    return ans;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c >> n >> m >> d >> q;

    vector<ll> a[m];
    vector<pair<ll, ll>> t[m];

    for(ll i = 1; i <= m; i++) cin >> w[i];

    for(ll i = 1; i <= n; i++){
        cin >> k[i];

        int temp = 0;

        for(ll j = 1; j <= k[i]; j++){
            ll u, v;
            cin >> u >> v;

            a[i].push_back(u), t[i].push_back({u, v});

            if(temp) s[u].push_back(temp), s[temp].push_back(u);

            temp = u;
        }
    }

    while(q--){
        ll x, y;
        cin >> x >> y;
        cout << dfs(x, y, 0) << endl;
    }

    return 0;
}
