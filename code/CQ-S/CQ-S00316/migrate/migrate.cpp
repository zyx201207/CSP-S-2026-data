#include <iostream>
using namespace std;
int c, t, n, mn, cnt;
long long ans, d, x[2000001];

void dfs(int depth, int cur, int& tar) {
    if (depth - 1 > mn) return;
    if (x[cur] <= x[tar]) {
        if (depth - 1 == mn) cnt++;
        else if (depth - 1 < mn) {
            mn = depth - 1;
            cnt = 1;
        }
        return;
    }
    for (int i = cur - 1; i >= 1 && x[cur] - x[i] <= d && x[i] >= x[tar]; i--) 
        dfs(depth + 1, i, tar);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios_base::sync_with_stdio(NULL), cin.tie(0);
    cin >> c >> t;
    while (t--) {
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            
            for (int j = 1; j < i; j++) {
                mn = 2e9;
                cnt = 0;
                dfs(1, i, j);
                //cout << i << ' ' << j << ' '<<mn <<' ' <<cnt<<'\n';
                ans += (cnt == 2);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
