
#include <bits/stdc++.h>
using namespace std;
int b[505],c[505][505],d[505][505],e[505],l,r,zzz,n,m,zz,q;
int ans=1000000000;
bool vis[505][505];
void dfs(int x,int y,int g,int h,int sum)
{
    if (vis[g][h])  return;
    vis[g][h]=1;
    if (x==y)
    {
        ans=min(ans,sum+d[g][h]);
        return;
    }
    if (sum>ans)  return;
    if (h+1<=e[g] && vis[g][h+1]==0)
    {
        dfs(c[g][h+1],y,g,h+1,sum);
        vis[g][h+1]=0;
    }
    if (h-1>=1 && vis[g][h-1]==0)
    {
        dfs(c[g][h-1],y,g,h-1,sum);
        vis[g][h-1]=0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=e[i];j++)
        {
            if (c[i][j]==x && vis[i][j]==0 && i!=g && j!=h)
            {
                dfs(x,y,i,j,sum+d[g][h]+d[i][j]);
                vis[i][j]=0;
            }
        }
    }
    return;
}
int main ()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> zzz >> n >> m >> zz >> q;
    for (int i=1;i<=m;i++)
    {
        cin >> b[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin >> e[i];
        for (int j=1;j<=e[i];j++)
        {
            cin >> c[i][j] >> d[i][j];
        }
    }
    while (q--)
    {
        memset(vis,0,sizeof(vis));
        ans=1000000000;
        cin >> l >> r;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=e[i];j++)
            {
                if (c[i][j]==l)
                {
                    dfs(l,r,i,j,d[i][j]);
                }
            }
        }
        cout << ans+b[l]+b[r] << "\n";
    }
    return 0;
}
