#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
int c, t, n, d, a[N], step[N], dp[N][N], ans = 0;
bool check(int l, int r) {
    memset(dp, 0, sizeof(dp));
    memset(step, 0, sizeof(step));
    int st = 1, now = l, cnt = 0;
    for(int i = l; i <= r; i++) {
        if(a[i] - a[now] > d) {
            now = i - 1;
            if(a[i] - a[now] <= d) st++;
            else return 0;
        }
        step[i] = st;
    }
    if(now != r) {
        if(a[r] - a[now] <= d) step[r] = st++;
        else return 0;
    }
    dp[l][0] = 1;
    for(int i = 1; i <= st; i++)
        for(int j = l + 1; step[j] <= i && j <= r; j++)
            for(int k = l; k < j; k++) {
                if(a[j] - a[k] > d) continue;
                dp[j][i] += dp[k][i - 1];
            }
    return dp[r][step[r]] == 2;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld %lld", &c, &t);
    while(t--) {
        ans = 0;
        scanf("%lld %lld", &n, &d);
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++)
                if(check(i, j)) ans++;
        printf("%lld\n", ans);
    }
}
