#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 5;
int n;
LL m;
LL a[N], sum[N];
inline void chmx(int& x, int y) { x = x > y ? x : y; }
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1;i <= n;++i) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= n;++i) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for (int i = 1;i <= n;++i) {
        int l = 1, r = i, p = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) r = mid - 1, p = mid;
            else l = mid + 1;
        }
        chmx(ans, i - p + 1);
    }
    printf("%d\n", ans);
    return 0;
}