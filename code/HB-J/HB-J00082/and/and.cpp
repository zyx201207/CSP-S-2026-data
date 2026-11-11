# include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node {
    int v, cnt;
} a[N];
int f[N][31], cnt[N], n, m;
int dp[N];
bool cmp(node x, node y) {
    //if (x.v == y.v) {
        return x.cnt > y.cnt;
    //}
    //return x.v > y.v;
}
long long dfs(int now, int cnt, int sum) {
    if (now > n) {
        return -1;
    }
    if (cnt == m) {
        return sum;
    }
    if (dp[now]) {
        return dp[now];
    }
    dp[now] = max(dfs(now + 1, cnt, sum), dfs(now + 1, cnt + 1, (cnt == 0) ? a[now].v : sum & a[now].v));
    return dp[now];
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int s = (1 << 30) - 1, mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i].v);
        s = s & a[i].v;
        mx = max(mx, a[i].v);
    }
    if (m == n) {
        printf("%d", s);
        return 0;
    }
    if (m == 1) {
        printf("%d", mx);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        long long temp = a[i].v;
        long long g = 1;
        while (temp) {
            if (temp & 1) {
                f[i][g]++;
                a[i].cnt++;
            }
            g++;
            temp >>= 1;
        }
    }
    sort(a + 1, a + 1 + n, cmp);
/*
    if (n <= 20) {
        printf("%lld", dfs(1, 0, 0));
        return 0;
    }
    */
    for (register int i = 1; i <= n; i++) {
        for (register int j = m; j >= 1; j--) {
            dp[j] = max(dp[j], ((j == 1) ? ((1 << 30) - 1) : dp[j - 1]) & a[i].v);
        }
    }
    printf("%d", dp[m]);
    return 0;
}
