#include<bits/stdc++.h>
#define int long long
#define For(i, n)for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define Rep(i, n) for (int i = (n); i >= 1; --i)
#define REP(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

const int N = 5e5 + 1000, M = 3e5 + 1000;
int a[N], ans[M], lst[N];

signed main() {
    freopen("card.in", "r", stdin); freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    For (i, n) cin >> a[i];
    For (i, n) {
        Rep (j, i-1) if (a[j] == a[i]) {lst[i] = j; break;}
    }
    // For (i, n) cout << lst[i] << " \n"[i == n];
    For (k, n) {
        vector<int> vst(n+1, 1);
        FOR (i, k, n) {
            if (lst[i] >= k && vst[lst[i]]) {
                FOR (j, lst[i], i-1) vst[j] = 0;
            }
        }
        // For (i, n) cout << vst[i] << " \n"[i == n];
        FOR (i, k, n) ans[a[i]] += vst[i];
    }
    For (i, m) cout << ans[i] << " \n"[i == m];
    return 0;
}