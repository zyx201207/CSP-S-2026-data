#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 5;
const ll INF = LLONG_MAX;

ll x[N];
int lx[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while (t--) {
        ll n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) {
            cin >> x[i];
        }
        x[n + 1] = INF;
        int r = 1;
        for (int l = 1; l <= n; ++l) {
            while(x[r + 1] - x[l] < d) {
                ++r;
            }
            lx[l] = r - l;
        }

        ll ans = 0;
        for (int i = 1; i <= n - 2; ++i) {
            if (lx[i] <= 1) continue;
            for (int j = i + 1; i <= j + lx[i]; ++j) {

            }
        }
        cout << ans << '\n';
    }



    return 0;
}
