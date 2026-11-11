#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int n, m;
int a[N];
int p[N];
int res;
int tot;
int pre[N], suf[N];

void dfs(int x) {
    if (x == n + 1) {
        int sum = 0;
        for (int i = 1; i <= n; i++) if (p[i]) sum++;
        if (sum != m) return;
        int ans;
        for (int i = 1; i <= n; i++) {
            if (p[i]) {
                ans = a[i];
                break;
            }
        }
        for (int i = 1; i <= n; i++) if(p[i]) ans = ans & a[i];
        res = max(res, ans);
        return;
    }
    p[x] = 0;
    dfs(x + 1);
    p[x] = 1;
    dfs(x + 1);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    bool flag1 = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int j;
        for (j = 1; j <= 20; j++) {
            if (a[i] == (1 << j) - 1) break;
        }
        if (j > 20) flag1 = true;
    }
    if (n <= 20) {
        dfs(1);
        cout << res;
        return 0;
    }
    if (m == 1) {
        for (int i = 1; i <= n; i++) res = max(res, a[i]);
        cout << res;
        return 0;
    } else if (m == n) {
        res = a[1];
        for (int i = 1; i <= n; i++) res = res & a[i];
        cout << res;
        return 0;
    }
    if (n <= 2000 && m == 2) {
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                res = max(res, a[i] & a[j]);
            }
        }
        cout << res;
        return 0;
    }
    if (!flag1) {
        for (int i = 1; i <= n; i++) res = max(res, a[i]);
        cout << res;
        return 0;
    }
    if (m == n - 1) {
        suf[0] = a[1], pre[n + 1] = a[n];
        for (int i = 1; i <= n; i++) suf[i] = suf[i - 1] & a[i];
        for (int i = n; i >= 1; i--) pre[i] = pre[i + 1] & a[i];
        for (int i = 1; i <= n; i++) {
            res = max(res, suf[i - 1] & pre[i + 1]);
        }
        cout << res;
        return 0;
    }
    sort(a + 1, a + n + 1, greater<int>());
    int ans = a[1];
    for (int i = 2; i <= m; i++) ans = ans & a[i];
    cout << ans;
    return 0;
}