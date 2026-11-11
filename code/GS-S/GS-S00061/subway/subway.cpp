#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e2+5;
const int MAXM = 5e5+5;
const ll INF = 1e18;
int _,n,m,d,q;
ll val[MAXM];
int k[MAXN];
struct node
{
    int id;
    ll dis;
};
vector<node>adj[MAXM];
ll dis[MAXN][MAXN];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>_>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++)
    {
        cin>>val[i];
    }
    for(int i = 1;i<=n;i++)
    {
        cin>>k[i];
        for(int j = 1;j<=k[i];j++)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].push_back({i,y});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i<=n;i++)
    {
        dis[i][i] = 0;
    }
    for(int i = 1;i<=m;i++)
    {
        int len = adj[i].size();
        for(int j = 0;j<len;j++)
        {
            for(int k = j+1;k<len;k++)
            {
                int x = adj[i][j].id,y = adj[i][k].id;
                ll u = adj[i][j].dis,v = adj[i][k].dis;
                dis[x][y] = dis[y][x] = min(dis[x][y],u+v);
            }
        }
    }
    for(int k = 1;k<=n;k++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i = 1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        int lenx = adj[x].size(),leny = adj[y].size();
        ll ans = INF;
        for(int j = 0;j<lenx;j++)
        {
            for(int k = 0;k<leny;k++)
            {
                int u = adj[x][j].id,v = adj[y][k].id;
                ll w1 = adj[x][j].dis,w2 = adj[y][k].dis;
                ans = min(ans,val[x]+val[y]+dis[u][v]+w1+w2);
            }
        }
        cout<<ans;
        if(i!=q)cout<<"\n";
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}