#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m, ans;
int a[N];
bool b[N];
bool cmp(int p, int q) {return p > q;}
void dfs(int pos) {
    if (pos == n + 1) {
        int res = 0, cnt = 0, idx = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i]) {res = a[i], idx = i; break;}
            // cnt += b[i];
        } 
        for (int i = 1; i <= n; i++) {
            if (b[i] && idx != i) res &= a[i];
            cnt += b[i];
        }
        if (cnt != m) return;
        ans = max(res, ans);
        return;
    }
    for (int i = 0; i <= 1; i++) {
        b[pos] = i;
        dfs(pos + 1);
    }
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 20) {
        dfs(1);
        cout << ans << '\n';
    } else {
        if (m == n) {
            ans = a[1];
            for (int i = 2; i <= n; i++) ans &= a[i];
            cout << ans << '\n';
        } else if (m == 1) {
            for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
            cout << ans << '\n';
        } else if (m == 2) {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++) {
                    if (i != j) ans = max(ans, a[i] & a[j]);
                }
            cout << ans << '\n';
        } else {
            sort(a + 1, a + n + 1, cmp);
            cout << a[m] << '\n';
        }
    }
    return 0;
}
