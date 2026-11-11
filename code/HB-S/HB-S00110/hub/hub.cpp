#include<bits/stdc++.h>
using namespace std ;
const int N = 40;
vector<int> g[N] ;
int popcnt[5000], a[N], f[N], book[230], ff[50][50];
int gtf(int idx)
{
    if(f[idx] == idx) return idx;
    return f[idx] = gtf(f[idx]) ;  
}
int mrg(int u, int v)
{
    u = gtf(u) ;
    v = gtf(v) ;
    if(u != v)
    {
        f[u] = v;
        return 1;
    }
    return 0;
}
int dfs1(int idx,int fa, int dep)
{
    if(book[idx]) return dep; 
    int ret = 2222;
    for(int i : g[idx])
    {
        if(i != fa) 
        {
            ret = min(ret, dfs1(i, idx, dep+1)) ;
        }
    }
    return ret;
}
int main()
{
    freopen("hub.in", "r", stdin) ;
    freopen("hub.out", "w", stdout) ;
    for(int i=1;i<=2048;i++)
    {
        popcnt[i] = popcnt[i>>1]+(i&1) ;
    }
    int c, t;
    cin>>c>>t;
    while(t--)
    {
        int n, m;
        cin>>n >>m;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
            ff[u][v] = ff[v][u] = 1;
        }
        int ans = 22222;
        for(int i=0;i<(1<<n);++i)
        {
            if(popcnt[i] != m) continue ;
            for(int j=1;j<=n;j++) f[j] = j, book[j] = 0;
            vector<int> V;
            for(int j=n;j>=1;--j)
            {
                if((i >>(j- 1)) & 1)
                {
                    V.push_back(j) ;
                    book[j] = 1;
                }
            }
            int x = m ;
            for(int j : V)
            {
                for(int k : V)
                {
                    if( ff[j][k])
                    {
                        x -= mrg(j, k) ;
                    }
                }
            }
            if(x > 2) continue ;
            int now = 0;
            for(int i=1;i<=n;i++)
            {
                now = max(now, dfs1(i, 0, 0)) ;
            }
            ans = min(ans, now) ;
        }
        cout << ans << '\n' ;
        for(int i=1;i<=n;++i) g[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) ff[i][j] =0;
        }
    }
}