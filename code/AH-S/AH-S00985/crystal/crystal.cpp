#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
long long a[MAXN];
unsigned long long dp[MAXN];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int res = 0;
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + (a[i] - a[i - 1]) * i;
        if (dp[i] > m) {
            res = i;
            break;
        }
    }

    if (res) cout << res;
    else cout << n;

    return 0;
}
