#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 700;
int w[N] ;
struct edge
{
    int to, wei ;
} ;
vector<edge> pass[N] ;
typedef long long ll ;
const ll inf = 2e18 ;
ll dis[505][505] ;  int c, n, m, d ,q;
int main()
{
    freopen("subway.in", "r", stdin) ;
    freopen("subway.out", "w", stdout) ;
    cin.tie(0) ;
    cout.tie(0) ;
    ios::sync_with_stdio(0) ;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {   
        cin>>w[i] ;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k ;
        for(int j=1;j<=k;j++)
        {
            int a, t;
            cin>>a>>t;
            pass[a].push_back({i, t}) ;
        }
    }
    memset(dis, 0x3f, sizeof dis) ;
    for(int i=1;i<=n;i++)
    {
        dis[i][i] = 0;
    }
    for(int k=1;k<=m;k++)
    {
        for(auto &j : pass[k])
        {
            for(auto &i : pass[k])
            {
                if(i.to != j.to)
                {
                    dis[i.to][j.to] = min(dis[i.to][j.to], (ll)i.wei + j.wei) ;
                }
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        // m+1~m+k
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j] ;
                }
            }
        }
    }
    while(q--)
    {
        int u, v;
        cin>>u>>v;
        ll ans = inf;
        for(auto &i : pass[u])
        {
            for(auto &j : pass[v])
            {
                ans = min(ans, dis[i.to][j.to] + i.wei + j.wei) ;
            }
        }
        ans += w[u] + w[v] ;
        cout << ans << '\n' ;
    }
}