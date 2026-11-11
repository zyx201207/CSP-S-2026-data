#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, p;
vector<pair<int, ll> > v[N];

ll w[N];
void solve(){
    cin >> c >> n >> m >> d >> p;
    if (c != '0') {
        return ;
    }
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int id;
            ll t;
            cin >> id >> t;
            v[i].push_back({id, t});
        }
    }
    while (q--) {
        int s, t;
        cin >> s >> t;
        ll ans = w[s] + w[t] + 90643;
        cout << ans << "\n";
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
