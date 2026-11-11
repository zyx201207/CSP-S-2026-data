#include<iostream>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
const int MAXN=5e3;
vector<int>g[MAXN+5],res;
int n,k;
ll dis[MAXN+5][MAXN+5];
ll ans=1e9;
bool fp;
void dfs(int u,int fa,int cnt,int pt)
{
    if(cnt>=k)
    {
        ll rs=-1;
        for(int i=1;i<=n;++i)
        {
            for(auto j:res)
            {
                rs=max(rs,dis[i][j]);
            }
        }
        ans=min(ans,rs);
        return;
    }
    if(pt>2)
    {
        return;
    }
    for(auto v:g[u])
    {
        if(v==fa)
        {
            continue;
        }
        bool tmp=fp;
        res.push_back(v);
        fp=true;
        dfs(v,u,cnt+1,pt);
        res.pop_back();
        fp=tmp;
        if(fp)
        {
            fp=false;
            dfs(v,u,cnt,pt+1);
        }
        else
        {
            fp=false;
            dfs(v,u,cnt,pt);
        }
        fp=tmp;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        for(int i=0;i<=MAXN;++i)
        {
            g[i].clear();
        }
        memset(dis,0x3f,sizeof(dis));
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<=n;++i)
        {
            dis[i][i]=0;
        }
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            dis[u][v]=1;
            dis[v][u]=1;
        }
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        fp=true;
        dfs(1,0,0,1);
        cout<<ans<<'\n';
    }
    return 0;
}
