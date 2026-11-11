#include<bits/stdc++.h>
#define int long long
#define For(i, n)for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define Rep(i, n) for (int i = (n); i >= 1; --i)
#define REP(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

const int N = 2e5 + 1000;
int n, m, a[N], s[N], ans;

void dfs(int x, int cnt, int res) {
    if (cnt == m) {
        if (res != (1<<31)-1LL) ans = max(ans, res); 
        return;
    }
    if (x > n) return;
    dfs(x+1, cnt+1, res&a[x]);
    dfs(x+1, cnt, res);
}
void solveBF() {
    dfs(1, 0, (1<<31)-1LL);
    cout << ans << '\n';
}

bool isA() {
    For (i, n) if ((a[i] & (a[i]+1)) != 0) return 0;
    return 1;
}
void solveAB() {
    ans = (1<<31) - 1LL;
    REP (i, n, n-m+1) ans &= a[i];
    cout << ans << '\n';
}

signed main() {
    freopen("and.in", "r", stdin); freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    For (i, n) cin >> a[i];
    s[0] = (1<<31) - 1LL;
    sort(a+1, a+n+1);
    For (i, n) s[i] = s[i-1] & a[i];
    if (n <= 20) solveBF();
    else if (m == 1) cout << *max_element(a+1, a+n+1) << '\n';
    else if (m == n) cout << s[n] << '\n';
    else if (m == 2) {
        For (i, n) FOR (j, i+1, n) ans = max(ans, (a[i]&a[j]));
        cout << ans << '\n';
    } 
    else if (m == n-1) {
        For (i, n) {
            int res = (1<<31)-1LL;
            For (j, n) {
                if (i == j) continue;
                res &= a[j];
            }
            ans = max(res, ans);
        }
        cout << ans << '\n';
    } 
    else if (isA() || (n & (n - 1)) == 0) solveAB();
    else solveBF();
    return 0;
}