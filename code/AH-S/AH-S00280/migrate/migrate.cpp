#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000005;

int c, T;

int n;
long long d;
long long p[MAXN];
long long dp[MAXN], dp2[MAXN];

long long Dis(int x, int y) {
    if ( x > y ) swap(x, y);
    return p[y] - p[x];
}

long long Calc(int x) {
    dp[x] = 0, dp2[x] = 1;
    for (int i = x + 1; i <= n; ++i) dp[i] = 1e9, dp2[i] = 0;
    for (int i = x + 1; i <= n; ++i) {
        for (int j = i - 1; j >= x; --j) {
            if ( Dis(j, i) > d ) break;
            if ( dp[j] + 1 < dp[i] ) {
                dp[i] = dp[j] + 1;
                dp2[i] = dp2[j];
            }
            else if ( dp[j] + 1 == dp[i] ) dp2[i] += dp2[j];
        }
    }

    int res = 0;
    for (int i = x + 1; i <= n; ++i) res += (dp2[i] == 2);
    return res;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> T;

    while (T--) {
        scanf("%d %lld", &n, &d);
        //cout << d << endl;

        for (int i = 1; i <= n; ++i) scanf("%lld", &p[i]);
        long long ans = 0;
        for (int i = 1; i <= n; ++i) ans += Calc(i);
        printf("%lld\n", ans);
    }
}
