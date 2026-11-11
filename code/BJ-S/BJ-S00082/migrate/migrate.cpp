#include<bits/stdc++.h>
#define int long long
#define inf INT_MAX
using namespace std;
int n,g[5010][5010],vis[5010][5010],x[5010],c,t,d;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) g[i][j] = inf,vis[i][j] = 0;
        for(int i = 1;i <= n;i++) cin >> x[i],g[i][i] = 0,vis[i][i] = 1;
        sort(x + 1,x + 1 + n);
        for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++) if(abs(x[j] - x[i]) <= d) g[i][j] = 1,vis[i][j] = 1;
        for(int k = 1;k <= n;k++) for(int i = 1;i < k;i++) for(int j = k + 1;j <= n;j++)
        {
            if(g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j],vis[i][j] = vis[i][k] * vis[k][j];
            else if(g[i][j] == g[i][k] + g[k][j]) vis[i][j] += vis[i][k] * vis[k][j];
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++) if(vis[i][j] == 2) ans++;
        cout << ans << endl;
    }
    return 0;
}
