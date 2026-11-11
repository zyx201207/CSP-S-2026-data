#include <bits/stdc++.h>
using namespace std;

int n;
long long a[3005], d, ans, minn = 1e18, x, y;

void dfs(int step, int land) {
    if (land == y) {
        if (step > minn) return ;
        if (step == minn) ans++;
        else minn = step, ans = 1;
        return;
    }
    for (int i = land + 1; i <= y; ++i) {
        if (a[i] - a[land] <= d) dfs(step + 1, i);
        else break;
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T; cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)cin >> a[i];
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j) {
                minn = 1e18, ans = 0, x = i; y = j;
                dfs(0, x);
                if (ans == 2) cnt++;
            }
        cout << cnt << endl;
    }
    return 0;
}
