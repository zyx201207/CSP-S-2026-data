#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[300005];
bool vis[300005];
int main()
{
    freopen("string.in", "w", "in");
    freopen("string.out", "r", "out");
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j<=n; j++)
        {
            if (vis[i])
            {
                memset(vis, false, sizeof(vis));
                vis[a[i]]=true;
            }
            vis[a[i]]=true;
        }
        for (int j=1; j<=m; j++) if (vis[j]) b[j]++;
    }
    for (int i=1; i<=m; i++) cout << b[i] << ' ';
}
