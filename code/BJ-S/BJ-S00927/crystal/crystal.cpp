#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int n, ans;
ll m, a[maxn], s[maxn];
int main() {
    ios::sync_with_stdio(false);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 1, j = 1; i <= n; i++) {
        while (a[i] * (i - j + 1) - (s[i] - s[j - 1]) > m) ++j;
        ans = max(ans, i - j + 1);
    } cout << ans << '\n';
    return 0;
}