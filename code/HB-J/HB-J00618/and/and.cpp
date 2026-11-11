//change into 01 backpak
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 5;
int n, m;
int a[N], book[N], maxx = INT_MIN;
ll ans = INT_MIN;
int val[N];
void dfs(int x, int sum, int res) {
    if (sum > m) {
        int tmp = val[1];
        for (int i = 2; i <= m; ++i)
            tmp &= val[i];
        ans = max(ans,(long long)(tmp));
        return ;
    }
    if (book[x]) return ;
    for (int i = x; i <= n; ++i) {
        if (!book[i]) {
            book[i] = 1;
            val[sum] += a[i];
            dfs (x + 1, sum + 1, (res & a[i]));
            val[sum] -= a[i];
            dfs (x + 1, sum + 1, res);
            book[i] = 0;
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 1, a[1]);
    cout << ans;
    return 0;
}
