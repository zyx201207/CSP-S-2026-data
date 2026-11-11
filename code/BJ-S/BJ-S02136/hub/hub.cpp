# include <bits/stdc++.h>
# define int long long
const int inf = 4e18;
const int N = 505;
using namespace std;
int n, k;
vector <int> e[N];
int f[N][N];
int calc(int yjh)
{
    int res = 0;
        for(int j = 0; j < n; j++)
        {
            if(yjh & (1 << j)) continue;
            int lhz = inf;
            for(int k = 0; k < n; k++)
            {
                if((yjh & (1 << k)) == 0)  continue;
                //cout << j << " " << k << "\n";
                lhz = min(lhz, f[j + 1][k + 1]);
            }
            res = max(res, lhz);
        }

    //cout << res << endl;
    return res;
}
void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            f[i][j] = inf;
        f[i][i] = 0;
    }
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        f[u][v] = f[v][u] = 1;
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
    int ans = inf;
    for(int i = 0; i < (1 << n); i++)
    {
        int c = 0;
        for(int j = 0; j < n; j++)
        {
            if((1 << j) & i) c++;
        }
        if(c == k)
        {
            //cout << i << endl;
            ans = min(ans, calc(i));
        }
    }
    cout << ans << "\n";
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    int c, T;
    cin >> c >> T;
    while(T--) solve();
    return 0;
}
