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
const int N = 2e6 + 10;
int x[N], pre[N], nxt[N], f[N], g[N], h[N];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int id, T;
    cin >> id >> T;
    while (T--)
    {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        int p = 1;
        for (int i = 1; i <= n; i++)
        {
            while (x[i] - x[p] > d) p++;
            pre[i] = p;
        }
        p = n;
        for (int i = n; i >= 1; i--)
        {
            while (x[p] - x[i] > d) p--;
            nxt[i] = p;
        }
        for (int i = 1; i <= n; i++)
        {
            f[i] = g[i] = h[i] = 0;
            int x = pre[i];
            if (x == i) continue;
            if (x == i - 1)
            {
                f[i] = f[x] + 1, g[i] = g[x] + h[x];
                continue;
            }
            f[i] = i - x;
            if (pre[x] < x)
            {
                if (nxt[pre[x]] >= x + 2) continue;
                if (nxt[pre[x]] == x + 1)
                {
                    h[i] += f[x] - (x - pre[x + 2]);
                    continue;
                }
                int pos = pre[x + 1];
                f[i] += f[x] - (x - pre[x]), g[i] += g[x] + (pos > pre[x] + 1 ? h[x] : 0);
                f[i] += pos - pre[x], h[i] += pre[x + 2] - pos;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += g[i] + h[i];
        cout << ans << '\n';
    }
    return 0;
}