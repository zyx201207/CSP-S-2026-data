#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
#define int long long
void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    set <int> st;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            st.insert(v[i]);
        }
        for (auto j : st) {
            mp[j]++;
        }
    }
    for (auto i : mp) {
        cout << i.second << ' ';
    }
}
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
