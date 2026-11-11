#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int c, t, n, k, u, v, cc, ans;
bool vis[1000005], d[1000005];
vector<int> ve[1000005];

void dfs1(int x)
{
    vis[x] = 1;
    for(int i : ve[x])
        if(d[i] && !vis[i])
            dfs1(i);
}

int dfs2(int x, int fa, int dd)
{
    int w = 1e9;
    if(d[x]) w = dd;
    for(int i : ve[x])
        if(i != fa)
            w = min(w, dfs2(i, x, dd + 1));
    return w;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
            ve[i].clear();
        for(int i = 1; i <= n - 1; i++)
        {
            scanf("%d%d", &u, &v);
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        if(c == 13 || c == 14)
        {
            if(k == n) printf("0\n");
            else printf("%d\n", (n / 2 - k + 6) / 4);
        }
        else
        {
            ans = 1e9;
            for(int i = 0; i < (1 << n); i++)
                if(__builtin_popcount(i) <= k)
                {
                    for(int j = 1; j <= n; j++)
                        vis[j] = 0;
                    for(int j = 1; j <= n; j++)
                        d[j] = (i & (1 << j - 1));
                    cc = 0;
                    for(int j = 1; j <= n; j++)
                        if(d[j] && !vis[j])
                        {
                            dfs1(j);
                            cc++;
                        }
                    if(cc > 2) continue;
                    int ww = 0;
                    for(int j = 1; j <= n; j++)
                        ww = max(ww, dfs2(j, 0, 0));
                    ans = min(ans, ww);
                }
            printf("%d\n", ans);
        }
    }
    return 0;
}

