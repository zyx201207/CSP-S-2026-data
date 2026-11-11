# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 5e2 + 5;
const int M = 5e5 + 5;
const int inf = 4e18;
int c, n, m, d, q;
int w[M];
int k[N];
vector <int> sub[M];
vector <int> t[M];
int f[N][N];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int st, tt;
            cin >> st >> tt;
            sub[st].push_back(i);
            t[st].push_back(tt);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = inf;
        }
        f[i][i] = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        int sz = t[i].size();
        //cout << sz << "\n";
        for(int j = 0; j < sz; j++)
        {
            for(int k = j + 1; k < sz; k++)
            {
                int u = sub[i][j], w1 = t[i][j];
                int v = sub[i][k], w2 = t[i][k];
                f[v][u] = f[u][v] = min(f[u][v], w1 + w2);
            }
        }
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = inf;
        //cout << sub[x].size() << " " << sub[y].size() << "\n";
        for(int i = 0; i < sub[x].size(); i++)
            for(int j = 0; j < sub[y].size(); j++)
                ans = min(ans, w[x] + w[y] + f[sub[x][i]][sub[y][j]] + t[x][i] + t[y][j]);
        cout << ans << "\n";
    }
    return 0;
}
