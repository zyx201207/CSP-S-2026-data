#include <bits/stdc++.h>
using namespace std;
namespace csps {
    typedef long long ll;
    const int MAXN = 5e5 + 5;
    int n;
    ll m, a[MAXN];
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ll cnt = 0;
        int ans = 0;
        for (int i = 1, j = 1; i <= n; i++) {
            j = max(j, i);
            while (j <= n && cnt <= m) {
                cnt += (a[j + 1] - a[j]) * (j - i + 1);
                j++;
            }
            ans = max(ans, j - i);
            cnt -= a[j] - a[i];
        }
        cout << ans << "\n";
    }
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    csps::main();
    return 0;
}