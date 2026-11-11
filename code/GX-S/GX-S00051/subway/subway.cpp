#include <bits/stdc++.h>
using namespace std;
int x,y,c,m,n,d,q,mint,w[500005],k[500005];
bool vis[500005];
vector<int> a[500005],t[500005];
void dfs(int v,int c)
{
    if (v == y)
    {
        mint = min(mint,c);
        return;
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= k[i];j++)
        {
            int nv = a[i][j];
            if (vis[nv] == 1) return;
            vis[nv] = 1;
            dfs(nv,c + t[i][j]);
            vis[nv] = 0;
        }
    }
}
int main()
{
    freopen("subway3.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
            cin >> x;
            t[i].push_back(x);
        }
    }
    for (int i = 1;i <= q;i++)
    {
        mint = 9999999;
        cin >> x >> y;
        dfs(x,0);
        cout << mint + w[x] + w[y] << endl;
    }
    return 0;
}
