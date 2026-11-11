#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5 + 10;
int a[N], ans[N];

signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int tmp = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != a[i - 1]) ans[a[i - 1]] = tmp;
        tmp++;
    }
    ans[a[n]] = tmp;
    for (int i = 1; i <= m; i++) cout << ans[i] - 1 << ' ';
    return 0;
}
