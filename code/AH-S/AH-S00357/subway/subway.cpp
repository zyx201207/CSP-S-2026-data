#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
    int to,t;
};
vector<edge> g[500005],line[502],g2[500005];
int x,y,c,n,m,d,q,t1[500005],num[502],ans=LLONG_MAX;//1 地铁站到站厅
bool in[500005],in2[502];
void dfs(int u,int dis)
{
    if(u==y)
    {
        ans=min(ans,dis);
        return ;
    }
    for(auto e:g[u])
    {
        if(!in2[e.to])
        {
            in2[e.to]=1;
            for(auto f:line[e.to])
                if(!in[f.to]&&dis+e.t+f.t<ans)
                {
                    in[f.to]=1;
                    dfs(f.to,dis+e.t+f.t);
                    in[f.to]=0;
                }
            in2[e.to]=0;
        }
    }
    return ;
}
struct node{
    int id,dis;
    bool operator<(const node  &x )const
    {return dis>x.dis;}
};
int di[500005];
bool vis[500005];
priority_queue<node> qu;
void dj()
{
    for(int i=1;i<=n;i++)
    {
      di[i]=LLONG_MAX;
      vis[i]=0;
    }
    di[x]=0;
    vis[x]=1;
    qu.push({x,0});
    while(!qu.empty())
    {
        node u=qu.top();
        qu.pop();
        if(vis[u.id])
            continue;
        vis[u.id]=1;
        for(auto e:g2[u.id])
        {
            if(di[e.to]>u.dis+e.t);
            {
               di[e.to]=u.dis+e.t;
               if(!vis[e.to])
                   qu.push({e.to,di[e.to]});
            }
        }
    }
    cout<<di[y]<<"\n";
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int i,j,a,t,u,v,dis,flag1=1;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;i++)
            cin>>t1[i];
    for(i=1;i<=n;i++)
    {
        cin>>num[i];
        if(num[i]>2)
            flag1=0;
        j=num[i];
        while(j--)
        {
            cin>>a>>t;
            line[i].push_back({a,t});
            g[a].push_back({i,t});
        }
    }
    if(flag1==1)
    {
        for(i=1;i<=n;i++)
        {
            u=0;
            v=0;
            dis=0;
            for(auto e:line[i])
            {
                dis+=e.t;
                if(u==0)
                    u=e.to;
                else
                    v=e.to;
            }
            g2[u].push_back({v,dis});
            g2[v].push_back({u,dis});
        }
    }
    for(i=1;i<=q;i++)
    {
        cin>>x>>y;
        if(flag1==1)
        {
            dj();
            continue;
        }
        ans=LLONG_MAX;
        in[x]=1;
        dfs(x,0);
        in[x]=0;
        cout<<ans+t1[x]+t1[y]<<"\n";
    }
    return 0;
}
