#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c, T;
int n;
ll d, x[N];
ll ans;
int sum[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while (T--) {
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)  cin >> x[i];
        for (int i = 1; i <= n; i++) {
            int far = upper_bound(x + i, x + n + 1, x[i] + d) - x - 1;
            if (far <= i + 1)  continue;
            int far2 = upper_bound(x + far, x + n + 1, x[far - 1] + d) - x - 1;
            int far3 = upper_bound(x + far, x + n + 1, x[far - 2] + d) - x - 1;
            int far4 = upper_bound(x + far, x + n + 1, x[far] + d) - x - 1;
            ans += (sum[i] + 1) * (far2 - far3);
            for (int j = far2; j < far4; j++)  sum[j]++; 
        }
        cout << ans << endl;
    }
    return 0;
}