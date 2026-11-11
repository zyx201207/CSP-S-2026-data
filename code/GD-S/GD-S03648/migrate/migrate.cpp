// O(n^2)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int ll

const int N = 2e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int id;
int n, lim;
int d[N];
int f[N], g[N];
int s[N];

void solve()
{
#define calc(l, r) (s[r] - s[(l) - 1])
    int ans = 0;
    cin >> n >> lim;
    rep(i, 1, n) cin >> d[i];
    rep(i, 1, n)
    {
        f[i] = 1, g[i] = 0;
        s[i - 1] = 0, s[i] = 1;
        // cerr << f[i] << ' ';
        int l = i, r = i;
        rep(j, i + 1, n)
        {
            while (d[j] - d[l] > lim) ++l;
            if (l == j) break;
            while (r + 1 < j && g[r + 1] == g[l]) ++r;
            g[j] = g[l] + 1, f[j] = calc(l, r);
            s[j] = s[j - 1] + f[j];
            // cerr << f[j] << ' ';
            ans += (f[j] == 2);
        }
        // cerr << '\n';
    }
    cout << ans << '\n';
#undef calc
}

signed main()
{
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> id >> T;
    while (T--) solve();
    cerr << fixed << setprecision(4) << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/
