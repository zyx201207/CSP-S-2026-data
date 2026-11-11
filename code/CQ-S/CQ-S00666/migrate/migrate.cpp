#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000010;
int n, m, a[N], ne[N], pr[N];
int L[N], R[N], ls[N], rs[N];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cas, T;cin >> cas >> T;
    while (T -- ) {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        int p = n;
        for (int i = n; i; i -- ) {
            while (a[p] - a[i] > m) p --;
            ne[i] = p;
        }
        p = 1;
        for (int i = 1; i <= n; i ++ ) {
            while (a[i] - a[p] > m) p ++;
            pr[i] = p;
        }
        int ans = 0;
        pr[n + 1] = n + 1;
        for (int i = 1; i <= n; i ++ ) {
            if (ne[pr[i]] == i && pr[i] < i) L[i] = L[pr[i]] + pr[i + 1] - pr[i];
            else L[i] = 0;
        }
        for (int i = n; i; i -- ) {
            if (ne[i] > i && pr[ne[i]] == i) R[i] = R[ne[i]] + ne[i] - ne[i - 1];
            else R[i] = 0;
        }
        for (int i = 1; i < n; i ++ ) {
            int A = 0, B = 0;
            if (ne[pr[i + 1]] == i + 1 && pr[i + 1] < i) {
                if (pr[i] == pr[i + 1] && pr[i] < i) A = L[pr[i]];
                A += pr[i + 2] - pr[i + 1];
            }
            if (pr[ne[i]] == i && ne[i] > i + 1) {
                if (ne[i] == ne[i + 1] && ne[i + 1] > i + 1) B = R[ne[i]];
                B += ne[i] - ne[i - 1];
            }
            ans += A * B;
            // cerr << i << ' ' << A * B << '\n';
        }
        cout << ans << '\n';
        // cerr << ans << '\n';
    }
    // cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
