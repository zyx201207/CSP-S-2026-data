#include<bits/stdc++.h>
using namespace std;
int w[500005];
struct way{
    int x, t;
};
vector<way> tem[500005];
int a[505][505], n;
long long f[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin >> c;
    int m, q;
    cin >> n >> m >> c >> q;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d", &w[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int x, t;
            scanf("%d%d", &x, &t);
            tem[x].push_back({i, t});
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            a[i][j] = 2e9;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 0;j < tem[i].size();j++)
        {
            for(int k = j + 1;k < tem[i].size();k++)
            {
                a[tem[i][j].x][tem[i][k].x] = min(a[tem[i][j].x][tem[i][k].x], tem[i][j].t + tem[i][k].t);
                a[tem[i][k].x][tem[i][j].x] = min(a[tem[i][k].x][tem[i][j].x], tem[i][j].t + tem[i][k].t);
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            f[i][j] = 1e18;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int k = 1;k <= n;k++)
        {
            if(a[i][k] != 2e9)
            {
                f[i][k] = a[i][k];
            }
            if(i == k) f[i][i] = 0;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int k = 1;k <= n;k++)
        {
            for(int j = 1;j <= n;j++)
            {
                f[i][j] = min(f[i][j], f[i][k] * 1ll + f[k][j]);
            }
        }
    }
    while(q--)
    {
        long long ans = 1e18;
        int x, y;
        scanf("%d%d", &x, &y);
        for(int j = 0;j < tem[x].size();j++)
        {
            for(int k = 0;k < tem[y].size();k++)
            {
                ans = min(ans, f[tem[x][j].x][tem[y][k].x] + tem[x][j].t + tem[y][k].t);
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
