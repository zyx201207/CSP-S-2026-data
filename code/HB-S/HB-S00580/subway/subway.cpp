#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int c,n,m,dd,q,cnt[N]={0};
long long w[N],d[N*22];
struct whm
{
    int t;
    long long w;
};
vector<whm> g[N*22];
bool vis[N*22];
struct lyr
{
    long long dis;
    int u;
    bool operator<(const lyr& o) const
    {
        return dis>o.dis;
    }
};
priority_queue<lyr> qq;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    int kk=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int ll=0;
        for(int j=1;j<=k;j++)
        {
            int a;
            long long t;
            cin>>a>>t;
            cnt[a]++;
            kk=max(kk,cnt[a]);
            g[a].push_back({a+cnt[a]*m,t});
            g[a+cnt[a]*m].push_back({a,t});
            if(ll!=0)
            {
                g[ll].push_back({a+cnt[a]*m,0});
                g[a+cnt[a]*m].push_back({ll,0});
            }
            ll=a+cnt[a]*m;
        }
    }
    while(q--)
    {
        for(int i=1;i<=m*(kk+1);i++) d[i]=1e18,vis[i]=0;
        while(!qq.empty()) qq.pop();
        int x,y;
        cin>>x>>y;
        qq.push({0,x});
        d[x]=0;
        while(!qq.empty())
        {
            lyr pp=qq.top();
            qq.pop();
            int u=pp.u;
            if(vis[u]) continue;
            vis[u]=1;
            if(u==y)
            {
                cout<<pp.dis+w[x]+w[y]<<"\n";
                break;
            }
            for(whm pj:g[u])
            {
                int v=pj.t;
                long long vv=pj.w;
                if(vv+d[u]<d[v])
                {
                    d[v]=d[u]+vv;
                    qq.push({d[v],v});
                }
            }
        }
    }
    return 0;
}