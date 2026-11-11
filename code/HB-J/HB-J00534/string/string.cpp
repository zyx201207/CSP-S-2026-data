#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
#define int long long
struct node {
    ll a;
    char c;
};
bool cmp(node a, node b) {
    return a.c < b.c;
}
void solve() {
    int n, sum = 0, ans = 0;
    vector<node> mp;
    unordered_map<char, int> mp2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        char c;
        cin >> a;
        cin >> c;
        mp2[c] += a;
    }
    for (auto it : mp2) {
        cerr << it.second << ' ' << it.first << el;
        mp.push_back({it.second, it.first});
    }
    vector<node> mp1 = mp;
    reverse(mp.begin(), mp.end());
    for (int i = 0; i < (mp.size() + 1) / 2;) {
        for (int j = 0; j < (mp.size() + 1) / 2;) {
            if (mp[i].c == mp1[j].c) {
                cout << ans;
                return;
            } else {
                int k = min(mp[i].a, mp1[j].a);
                cerr << k << el;
                mp[i].a -= k;
                mp1[j].a -= k;
                ans += k;
                if (mp[i].a == 0) {
                    i++;
                }
                if (mp1[j].a == 0) {
                    j++;
                }
            }
        }
    }
    cout << ans;
}
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
