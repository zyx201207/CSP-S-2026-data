#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int>e[N];
int n,k;
bool vis[N];
int ans[N];
int fa[N];
int f[N][20];
int dep[N];
int s,res;
int fin(int x)
{
    return x == fa[x]?x:fa[x] = fin(fa[x]);
}
void merge(int x,int y)
{
    x = fin(x),y = fin(y);
    if(x!=y)
    {
        fa[y] = x;
    }
}
bool check(int x,int *ans)
{
    for(int i = 0;i<x;++i)
    {
        fa[ans[i]] = ans[i];
    }
    for(int i = 0;i<x;++i)
    {
        for(int v:e[ans[i]])
        {
            if(vis[v])
            {
                merge(ans[i],v);
            }
        }
    }
    int num = 0;
    for(int i = 0;i<x;++i)
    {
        if(fa[ans[i]] == ans[i])
        {
            ++num;
            if(num>2)
            {
                return 0;
            }
        }
    }
    return 1;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])
    {
        swap(x,y);    
    }
    for(int i = s;i>=0;--i)
    {
        if(dep[x]-(1<<i)>=dep[y])
        {
            x = f[x][i];
        }
    }
    if(x == y)
    {
        return x;
    }
    for(int i = s;i>=0;--i)
    {
        if(f[x][i]!=f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int dis(int x,int y)
{
    return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
}
void dfs(int x,int last)
{
    if(!check(x,ans))
    {
        return;
    }
    if(x == k)
    {
        int maxx = 0;
        for(int i = 1;i<=n;++i)
        {
            if(vis[i])
            {
                continue;
            }
            int minn = 1e9;
            for(int j = 0;j<k;++j)
            {
                minn = min(minn,dis(i,ans[j]));
            }
            maxx = max(maxx,minn);
        }
        res = min(res,maxx);
        return;
    }
    for(int i = last+1;i<=n;++i)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            ans[x] = i;
            dfs(x+1,i);
            vis[i] = 0;
        }
    }
}
void dfs1(int x,int fa)
{
    f[x][0] = fa;
    for(int v:e[x])
    {
        if(v!=fa)
        {
            dep[v] = dep[x]+1;
            dfs1(v,x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for(int _ = 1;_<=t;++_)
    {
        cin >> n >> k;
        s = 31-__builtin_clz(n);
        for(int i = 1;i<=n;++i)
        {
            vis[i] = 0;
            e[i].clear();
        }
        for(int i = 1;i<n;++i)
        {
            int x,y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        dfs1(1,0);
        for(int i = 1;i<=s;++i)
        {
            for(int j = 1;j<=n;++j)
            {
                f[j][i] = f[f[j][i-1]][i-1];
            }
        }
        res = 1e9;
        dfs(0,0);
        cout << res << '\n';
    }
    return 0;
}