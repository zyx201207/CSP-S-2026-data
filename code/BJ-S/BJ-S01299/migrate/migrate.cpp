#include <bits/stdc++.h>
using namespace std;
// 1-based, C-style I/O
using ll = long long;
void solve1(int n, ll d, const vector<ll>& x) {
    vector<vector<pair<ll, int>>> f(n + 1, vector<pair<ll, int>>(n + 1));
    for (int i = 1; i <= n; ++i) {
        f[i][i] = {0, 1};
    }
    ll ans = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            auto j = i + len - 1;
            ll mn = numeric_limits<ll>::max();
            int cnt = 0;
            for (int p = 1; p < j; ++p) {
                if (x[j] - x[p] <= d) {
                    if (f[i][p].first < mn) {
                        mn = f[i][p].first;
                        cnt = f[i][p].second;
                    } else if (f[i][p].first == mn) {
                        cnt += f[i][p].second;
                    } 
                }
            }
            if (cnt > 3) {
                cnt = 3;
            }
            if (i < j && cnt == 2) {
                ++ans;
            }
            f[i][j] = {mn + 1, cnt};
        }
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    int c, t;
    scanf("%d%d", &c, &t);
    while (t--) {
        int n;
        ll d;
        scanf("%d%lld", &n, &d);
        vector<ll> x(n + 1);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &x[i]);
        }
        solve1(n, d, x);
    }
    return 0;
}