#include <bits/stdc++.h>
using namespace std;
int a[1000005], l[1000005], l1[1000005];
vector<int> g[100005];
int ans = 1e9 + 10;
void solve(int u, int v, int k)
{
    if(u == v)
    {
        ans = min(ans, k);
        return;
    }
    for(int i = 0; i < g[u].size(); i++)
    {
        solve(g[u][i], v, k + 1);
    }
    return;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
        for(int i = 1; i <= m; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            for(int j = 1; j <= k; j++)
            {
                cin >> l[j] >> l1[j];
            }
            for(int j = 1; j <= k - 1; j++)
            {
                g[l[j]].push_back(l[j + 1]);
            }
        }
        for(int i = 1; i <= q; i++)
        {
            int x, y;
            cin >> x >> y;
            ans = 1e9 + 10;
            solve(x, y, 0);
            ans++;
            ans *= l1[1];
            ans = ans + a[x] + a[y];
            cout << ans << endl;
        }
    return 0;
}