#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], ans;
void dfs(int pos, int cnt, int sum) {
    if (cnt >= m) {
        ans = max(ans, sum);
        return;
    }
    for (int i = pos + 1; i <= n; i++) dfs(i, cnt + 1, sum & a[i]);
}
bool SpecialA() {
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (int j = 0; j <= 30; j++)
            if (abs(a[i] - (pow(2, 30) - 1)) < 0.000001) flag = true;
        if (!flag) return false;
    }
    return true;
}
bool SpecialB() {
    for (int i = 1; i <= n; i++)
        if (a[i] >= 4) return false;
    return true;
}
bool cmp(int x, int y) { return x > y; }
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 20) {
        for (int i = 1; i <= n; i++) dfs(i, 1, a[i]);
        cout << ans;
    } else if (m == 1) {
        for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
        cout << ans;
    } else if (m == n) {
        ans = a[1];
        for (int i = 1; i <= n; i++) ans &= a[i];
        cout << ans;
    } else if (m == 2) {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) ans = max(ans, a[i] & a[j]);
        cout << ans;
    } else if (SpecialA()) {
        sort(a + 1, a + n + 1, cmp);
        cout << a[m];
    } else if (SpecialB()) {
        sort(a + 1, a + n + 1, cmp);
        if (a[m] == 3) cout << 3;
        if (a[m] == 2) cout << 2;
        if (a[m] == 1) {
            int ans;
            for (int i = 1; i <= n; i++)
                if (a[i] == 3 || a[i] == 1) ans++;
            if (ans >= m) cout << 1;
            else cout << 0;
        } else cout << 0;
    } else ;
    return 0;
}
