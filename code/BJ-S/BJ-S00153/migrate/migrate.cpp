#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, ans = 2147483647, tongji = 0, res = 0, x[2000003];
void dfs(long long a, long long b, long long cur, long long curnum) {
    if (cur == b) {
        if (curnum < ans) {
            tongji = 1;
            ans = curnum;
        } else if (curnum == ans) {
            tongji++;
        }
        return;
    }
    if (curnum > ans) {
        return;
    }
    for (int i = cur + 1; i <= b; i++) {
        if (x[i] - x[cur] <= d) {
            dfs(a, b, i, curnum + 1);
        } else {
            break;
        }
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> d;
        res = 0;
        for (int j = 1; j <= n; j++) {
            cin >> x[j];
        }
        for (int j = 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {
                tongji = 0;
                ans = 2147483647;
                dfs(j, k, j, 0);
                if (tongji == 2) {
                    res++;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}
