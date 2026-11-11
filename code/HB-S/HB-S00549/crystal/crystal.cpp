#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n;
ll m, a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int hd = 1, tl = 1;
    ll sum = a[1];
    int ans = 0;
    while (hd <= tl && tl <= n) {
        ans = max(ans, tl - hd + 1);
        tl++;
        sum += a[tl];
        int len = tl - hd + 1;
        // cout << len << " " << hd << " " << tl << " " << sum << endl;
        if ((len) * a[tl] - sum <= m) {
            continue;
        }
        else {
            while (hd < tl) {
                int len1 = tl - hd + 1;
                if ((len1) * a[tl] - sum <= m) {
                    break;
                }
                sum -= a[hd];
                hd++;    
            }
        }
        // cout << len << endl;
    }
    cout << ans << endl;
    return 0;
}