#include <bits/stdc++.h>
using namespace std;
set<int> all(set<int> a, set<int> b) {
    set<int> res;
    for (int it : a) {
        if (b.find(it) != b.end()) res.insert(it);
    }
    return res;
}
int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<set<int>> bit(31);
    set<int> ans;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int p = a[i];
        for (int j = 0; j <= 30; j++) {
            if (p & 1) bit[j].insert(i);
            p >>= 1;
            if (p == 0) break;
        }
    }
    for (int j = 30; j >= 0; j--) {
        if (bit[j].size() >= m) {
            if (ans.size() == 0) {
                ans = bit[j];
            } else {
                set<int> tmp = all(ans, bit[j]);
                if (tmp.size() >= m) ans = tmp;
            }
        }
    }
    int res = (1ll<<31) - 1;
    auto it = ans.begin();
    while (it != ans.end()) {
        res &= a[*it];
        it++;
    }
    cout << res;
    return 0;
}