#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6 + 5, M = 5005;
ll a[N];
ll n, d;
ll dp[N], dp2[N];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll ans = 0;
        for (int k = 1; k < n; k++) {
            memset(dp, 0, sizeof(dp));
            memset(dp2, 0, sizeof(dp2));
            for (int i = k + 1; i <= n; i++) {
                int j = i;
                while (j >= k && a[i] - a[j] <= d) j--;
                if (j == i) dp2[i] = 0;
                else dp2[i] = dp2[j + 1] + 1;
         //       cout << j << " " << dp2[i] << endl;
            }
           // cout << "\n\n";
//            cout << "dp: ";
            for (int i = k + 1; i <= n; i++) {
                for (int j = i; j >= k && a[i] - a[j] <= d; j--) {
                    if (dp2[j] + 1 == dp2[i]) dp[i]++;
                }
  //              cout << i << " " << dp[i] << endl;
            }
      //      cout << endl;
            for (int i = k; i <= n; i++) {
                if (dp[i] - dp[k] == 2) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}