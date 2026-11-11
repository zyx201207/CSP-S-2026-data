// crystal
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
const int N = 5e5 + 1023;
int n, ans = 1;
LL m, a[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    LL res = 0;
    for (int i = 2, j = 1; i <= n; ++i) {
        res += (a[i] - a[i - 1]) * (i - j);
        while (j < i && res > m) res -= a[i] - a[j++];
        ans = max(ans, i - j + 1);
    }
    cout << ans << '\n';
    return 0;
}
