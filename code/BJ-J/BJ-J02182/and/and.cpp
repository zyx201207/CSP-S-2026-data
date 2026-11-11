#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long a[N];
long long ans;
int n, m;

void dfs(int x, int cnt, long long awy) {
    //cout << "/";
    if (cnt == m) {
        ans = max(ans, awy);
        //cout << x << " " << awy << " " << cnt << endl;
        return;
    }
    if (x == n) {
        return;
    }
    if (n - x > m - cnt) {
        dfs(x + 1, cnt, awy);
    }
    if (cnt != 0) {
        dfs(x + 1, cnt + 1, awy & a[x + 1]);
    } else {
        dfs(x + 1, cnt + 1, a[x + 1]);
    }
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}