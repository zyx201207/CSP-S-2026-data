#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
#define int long long
void solve() {
    int n, m, cnt = 0, ans = 0;
    cin >> n >> m;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]] ++;
    }
    sort (v.begin(), v.end());
    for (int i = 1; i <= n; i++)
        if (mp[v[n - i]] > m)  {
            cout << (ans & v[n - i]);
            return ;
        }
}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
