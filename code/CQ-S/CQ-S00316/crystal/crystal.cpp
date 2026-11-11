/*
暴力
*/

#include <cstdio>
#include <algorithm>
using namespace std;
int n, l, r, mid, ans; // 二分结束点
long long m, a[500001], sum[500001], s;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    for (int i = 1; i <= n; i++) {
        s = (i - 1) * a[i] - sum[i-1];
        int j;
        for (j = 1; s > m && j < i; j++) 
            s -= a[i] - a[j];
        ans = max(ans, i - j + 1);
    }
    printf("%d", ans);
    return 0;
}

// wjy 是猫娘！！！（详见 MINERALSALT）