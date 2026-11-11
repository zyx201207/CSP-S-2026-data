#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int a[200005];
bool can[200005];

int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        can[i] = 1;
    }
    for (int k = 29; k >= 0; --k) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] & (1 << k) && can[i]) {
                cnt++;
            }
        }
        if (cnt >= m) {
            ans += (1 << k);
            for (int i = 1; i <= n; ++i) {
                if (!(a[i] & (1 << k) && can[i])) {
                    can[i] = 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
