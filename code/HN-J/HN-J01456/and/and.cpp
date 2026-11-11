#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define sqr(x) ((x) * (x))
using namespace std;

constexpr unsigned int NR = 2e5 + 5;
int n, m;
ll a[NR];
bitset<NR> b;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    ll ans = 0;
    for (int i = 30; i >= 0; -- i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++ j)
            if (!b[j] && ((a[j] >> i) & 1))
                cnt ++;
        if (cnt >= m) {
            ans += (1 << i);
            for (int j = 1; j <= n; ++ j)
                if (!b[j] && !((a[j] >> i) & 1))
                    b[j] = 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int oT_To = 1;
    // cin >> oT_To;
    while (oT_To --)
        solve();
    return 0;
}
