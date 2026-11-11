#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m; scanf("%lld %lld", &n, &m);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(m == 1) {
        cout << *max_element(a.begin(), a.end());
        return 0;
    }
    if(m == 2) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(j == i) continue;
                ans = max(ans, a[i] & a[j]);
            }
        }

        cout << ans << endl;
        return 0;
    }

    map<int, int> bkt;
    for(int i = 1; i <= n; i++) {
        bkt[a[i]]++;
    }

    int ans = 0;
    for(auto& [x, y]: bkt) {
        if(y >= m) {
            ans = max(ans, x);
        }
    }

    cout << ans << endl;
}
