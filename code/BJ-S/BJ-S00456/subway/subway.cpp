#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
int c,n,m,d,q,w[N],k[N],a[N][N],t[N][N],x,y,pos[N][N],ans,tim[N][N];
vector<int> vec[N];
void dfs(int u,int idx,int sum,bool flag)
{
    if (u == y)
    {
        ans = min(ans,sum+tim[u][idx]);
        return;
    }
    if (!flag)
        for (int tmp:vec[u])
        {
            if (tmp == idx)
                continue;
            dfs(u,tmp,sum+tim[u][idx]+tim[u][tmp],true);
        }
    for (int i = pos[u][idx]+1; i <= k[idx]; i++)
        dfs(a[idx][i],idx,sum,false);
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int i,j;
    cin >> c >> n >> m >> d >> q;
    for (i = 1; i <= m; i++)
        cin >> w[i];
    for (i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            vec[a[i][j]].push_back(i);
            pos[a[i][j]][i] = j;
            tim[a[i][j]][i] = t[i][j];
        }
    }
    while (q--)
    {
        cin >> x >> y;
        ans = 1e18;
        for (int tmp:vec[x])
            dfs(x,tmp,tim[x][tmp],true);
        cout << ans+w[x]+w[y] << "\n";
    }
    return 0;
}