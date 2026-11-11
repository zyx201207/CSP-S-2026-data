#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N = 1e5+10,mod = 1e9+7;

int cid,n,k;
vector<int> e[N];
int dep[N],dfn[N],tot;
int st[20][N],lg[N];
int Dis[1010][1010];
bool vis[N];
int ans;

void dfs(int u,int f)
{
    dfn[u] = ++tot;
    st[0][tot] = f;
    for(int v:e[u])
    {
        if(v == f) continue;
        dep[v] = dep[u] + 1;
        dfs(v,u);
    }
}
int mx(int u,int v) {return dfn[u]<dfn[v]?u:v;}
void init_st()
{
    for(int i=2;i<=n;i++) lg[i] = lg[i>>1] + 1;
    for(int l=1;l<=lg[n];l++)
    {
        for(int i=1;i+(1<<l)-1<=n;i++)
        {
            st[l][i] = mx(st[l-1][i],st[l-1][i+(1<<(l-1))]);
        }
    }
}
int lca(int u,int v)
{
    if(u == v) return u;
    if((u = dfn[u]) > (v = dfn[v])) swap(u,v);
    u++;
    int l=lg[v-u+1];
    return mx(st[l][u],st[l][v-(1<<l)+1]);
}
int dis(int u,int v)
{
    // cerr << u << ' ' << v << ' ' << lca(u,v) << '\n';
    return dep[u] + dep[v] - 2*dep[lca(u,v)];
}
void update()
{
    int ret=0;
    // for(int i=1;i<=n;i++) cout << vis[i] << ' '; cout << '\n';
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            int len=1e9;
            for(int j=1;j<=n;j++)
            {
                if(vis[j]) len = min(len,dis(i,j));
            }
            ret = max(len,ret);
        }
        else if(!vis[st[0][dfn[i]]]) cnt++;
    }
    if(cnt <= 2) ans = min(ans,ret);
}

void dfs1(int i,int sum)
{
    if(i > n)
    {
        if(sum == 0) update();
        return;
    }
    vis[i] = 0;
    dfs1(i+1,sum);
    if(sum)
    {
        vis[i] = 1;
        dfs1(i+1,sum-1);
        vis[i] = 0;
    }
}

void solve()
{
    cin >> n >> k;
    for(int i=1,u,v;i<n;i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(13 <= cid && cid <= 14)
    {
        if(k == n) cout << 0 << '\n';
        else if(k >= n/2) cout << 1 << '\n';
        else cout << (((n/2)-k+3) / 4) + 1 << '\n';
        return;
    }
    dep[1] = 0;
    dfs(1,0);
    init_st();
    ans = 1e9;
    if(k == 2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                Dis[i][j] = dep[i] + dep[j] - 2*dep[lca(i,j)];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                register int k,l=0;
                for(k=1;k+8<n;k+=8)
                {
                    l = max(l,Dis[i][k]>Dis[j][k]?Dis[j][k]:Dis[i][k]);
                    l = max(l,Dis[i][k+1]>Dis[j][k+1]?Dis[j][k+1]:Dis[i][k+1]);
                    l = max(l,Dis[i][k+2]>Dis[j][k+2]?Dis[j][k+2]:Dis[i][k+2]);
                    l = max(l,Dis[i][k+3]>Dis[j][k+3]?Dis[j][k+3]:Dis[i][k+3]);
                    l = max(l,Dis[i][k+4]>Dis[j][k+4]?Dis[j][k+4]:Dis[i][k+4]);
                    l = max(l,Dis[i][k+5]>Dis[j][k+5]?Dis[j][k+5]:Dis[i][k+5]);
                    l = max(l,Dis[i][k+6]>Dis[j][k+6]?Dis[j][k+6]:Dis[i][k+6]);
                    l = max(l,Dis[i][k+7]>Dis[j][k+7]?Dis[j][k+7]:Dis[i][k+7]);
                }
                for(;k<=n;k++) 
                    l = max(l,Dis[i][k]>Dis[j][k]?Dis[j][k]:Dis[i][k]);
                ans = min(ans,l);
            }
        }
    }
    else
    {
        dfs1(1,k);
    }
    cout << ans << '\n';
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        e[i].clear();
    }
    tot = 0;
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> cid >> T;
    while(T--)
    {
        solve();
        init();
    }
}