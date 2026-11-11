#include <bits/stdc++.h>
using namespace std;
constexpr int N = 500005;
int n, ans;
long long m, a[N], s[N];
bool av(int l, int r) {
    return a[r] * (r-l+1) - (s[r] - s[l-1]) <= m;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", a+i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i];
    int l = 1;
    for (int r = 1; r <= n; ++r) {
        while (!av(l, r)) ++l;
        // printf("%d %d\n", l, r);
        ans = max(ans, r-l+1);
    } printf("%d\n", ans);
    return 0;
}