#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m, a[N], p[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i =  1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    int ans = 0, ps = 1;
    for(int i = 1; i <= n; ++i) {
        while(a[i] * (i - ps + 1) - (p[i] - p[ps - 1]) > m) ++ps;
        ans = max(ans, i - ps + 1);
    }
    printf("%d\n", ans);
}
