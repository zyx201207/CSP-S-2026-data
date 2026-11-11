#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define m_p make_pair
#define fi first
#define se second
#define pcnt __builtin_popcountll
using namespace std;
const int inf = (sizeof(int) == 4 ? 0x3f3f3f3f : 0x3f3f3f3f3f3f3f3f);
int a[500010], f[510][510];
vpii v[500010];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int id, n, m, d, q;
    cin >> id >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x, y;
            cin >> x >> y;
            v[x].pb({i, y});
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= m; i++) for (auto [j, p] : v[i]) for (auto [k, q] : v[i]) f[j][k] = min(f[j][k], p + q);
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = inf;
        for (auto [i, p] : v[x]) for (auto [j, q] : v[y]) ans = min(ans, f[i][j] + p + q);
        cout << ans + a[x] + a[y] << '\n';
    }
    return 0;
}