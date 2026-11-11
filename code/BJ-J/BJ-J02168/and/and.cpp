// ========== ACACACACAC ==========
// This is T3.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int m, n;
int ans;

struct Num {
    int num, cnt;
} a[N];

bool cmp(Num a, Num b) {
    if (a.cnt == b.cnt) return a.num > b.num;
    return a.cnt > b.cnt;
}

inline void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].num;
        a[i].cnt = __builtin_popcount(a[i].num);
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= m; ++i) {
        if (i == 1) ans = a[i].num;
        else ans &= a[i].num;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}