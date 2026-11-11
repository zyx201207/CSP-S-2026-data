#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, n, m, d, q, k[510], a;
ll w[500100], f[510][510];
vector<int> cnt[500100];
map<int, ll> t[510];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &w[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++)
            scanf("%d", &a), scanf("%lld", &t[i][a]), cnt[a].push_back(i);
    }
    memset(f, 127, sizeof(f));
    for (int i = 1; i <= m; i++) {
        for (auto j : cnt[i])
            for (auto k : cnt[i])
                if (j != k)
                    f[j][k] = min(f[j][k], t[j][i] + t[k][i]);
                else
                    f[j][k] = 0;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (f[i][k] < (1ll << 60) && f[k][j] < (1ll << 60))
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        ll ans = 1ll << 60;
        for (auto s : cnt[l])
            for (auto ts : cnt[r])
                ans = min(ans, t[s][l] + f[s][ts] + t[ts][r]);
        printf("%lld\n", w[l] + ans + w[r]);
    }
}
