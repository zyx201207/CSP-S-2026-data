#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200007];
int in[200007];
int tot;
int gg;
bool vis[200007];
bool v[200007];
void dfs(int i,int g,int ans)
{
    if(ans > in[g]) in[g] = ans;
    else return ;
    if(i == 0)
    {
        return ;
    }
    if(g == 0)
    {
        if(ans > gg)
        {
            gg = ans;
            for(int j = 1; j <= n; j++)
            {
                v[j] = vis[j];
            }
        }
        return ;
    }
    if(g > i)
    {
        return ;
    }
    in[g] = ans;
    vis[i] = 1;
    dfs(i - 1,g - 1, (ans & a[i]));
    vis[i] = 0;
    dfs(i - 1,g, ans);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a + 1, a + 1 + n);
    for(int i = n ; i >= n - m; i--)
    {
        if(v[i]) continue;
        gg = 0 ;
        for(int i = 1; i <= n; i++)
        {
            in[i] = 0;
        }
        dfs(i - 1,m - 1,a[i]);
        tot = max(gg,tot);
    }
    printf("%d",tot);
    return 0;
}
