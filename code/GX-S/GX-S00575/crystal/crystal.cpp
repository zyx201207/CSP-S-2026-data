#include <iostream>
#include <algorithm>
using namespace std;

constexpr unsigned int MAXN = 500005;
long long n, m, a[MAXN], cost[MAXN];

int main() {
    freopen("crystal.in",  "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (long long i = 1;i <= n;++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    long long ans = 0, costnow = 0;
    for (long long i = 1, j = 1;i <= n && j <= n;) {
        if (costnow <= m) {
            ans = max(ans, j - i + 1);
            costnow += (a[j + 1] - a[j]) * (j + 1 - i);
            j++;
        } else {
            costnow += a[i] - a[j];
            i++;
        }
    }

    cout << ans << "\n";

    return 0;
}
// O(n log n) 100pts? 15:12