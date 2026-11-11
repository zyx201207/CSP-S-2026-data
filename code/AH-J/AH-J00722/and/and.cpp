#include <bits/stdc++.h>
#define ft first
#define nd second
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 2e5 + 10;
int n, m, a[N], ans, dp[N];

void dfs(int cur, int cnt, int sum) {
    if (cnt == m) {
        ans = max(ans, sum);
        return ;
    }
    if (cur > n) return ;
    dfs(cur + 1, cnt + 1, sum & a[cur]);
    dfs(cur + 1, cnt, sum);
    return ;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 20) {
        dfs(1, 0, pow(2, 31) - 1);
        cout << ans;
        return 0;
    }
    dp[0] = pow(2, 31) - 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            dp[j] = max(dp[j], dp[j - 1] & a[i]);
        }
    }
    cout << dp[m];
    return 0;
}
