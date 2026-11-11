#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fir first
#define sec second
const int N = 5e5 + 10;

int c, n, m, d, q, w[N];
vector < pair <int, int> > v[N];
int e[510][510];

void insert()
{
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int a, t;
            cin >> a >> t;
            v[a].push_back({i, t});
        }
    }
}

void work()
{
    insert();
    memset(e, 0x3f, sizeof(e));
    for(int i = 1; i <= n; i++)
        e[i][i] = 0;
    for(int i = 1; i <= m; i++)
        for(auto j : v[i])
            for(auto k : v[i])
                e[j.fir][k.fir] = min(e[j.fir][k.fir], j.sec + k.sec);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 1e18;
        for(auto i : v[x])
            for(auto j : v[y])
                ans = min(ans, i.sec + j.sec + e[i.fir][j.fir]);
        ans += w[x] + w[y];
        cout << ans << '\n';
    }
}

signed main()
{
    freopen("subway.out", "w", stdout);
    freopen("subway.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    work();
}