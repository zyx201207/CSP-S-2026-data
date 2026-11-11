#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5005;
int c, T, n, dis[N][N], cnt[N][N];
long long d, a[N], sum[N];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--) {
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = 0;
                cnt[i][j] = 0;
            }
        int ans = 0;
        for (int i = 1; i <= n; ++i) scanf("%lld", a+i);
        for (int r = 1; r <= n; ++r) {
            dis[r][r] = 0; cnt[r][r] = 1;
            for (int i = 1; i <= n; ++i) sum[i] = 0;
            for (int l = r-1, next = r; l >= 1; --l) {
                while (a[next] - a[l] > d) {
                    if (dis[next][r] == dis[next-1][r]) sum[dis[next-1][r]] -= cnt[next][r];
                    --next;
                }
                if (l == next) break;
                // printf("[%d -%d- %d] ", l, next, r);
                if (next == r) {
                    dis[l][r] = cnt[l][r] = 1;
                    sum[dis[l][r]] += cnt[l][r];
                    // printf("dis = %d; cnt = %d\n", dis[l][r], cnt[l][r]);
                    continue;
                }
                dis[l][r] = dis[next][r] + 1;
                cnt[l][r] = sum[dis[next][r]];
                sum[dis[l][r]] += cnt[l][r];
                if (cnt[l][r] == 2) ++ans;
                // printf("dis = %d; cnt = %d\n", dis[l][r], cnt[l][r]);
            }
        } printf("%d\n", ans);
    }
    return 0;
}