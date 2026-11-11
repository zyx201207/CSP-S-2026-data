#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long

int n, ans;
ll m, a[N], w[N];

bool check(int l, int r) {
    return (w[r] - w[l - 1]) - (a[n] - a[r]) * (r - l + 1) <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) w[i] = w[i - 1] + a[n] - a[i];
    for (int i = 1; i <= n; i++) {
        int L = 1, R = i;
        if (check(L, i)) R = L;
        while (L + 1 < R) {
            int M = (L + R) >> 1;
            if (check(M, i)) R = M;
            else L = M;
        } ans = max(ans, i - R + 1);
    }
    printf("%d\n", ans);
    return 0;
}