#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,k;
int c,T;
int w[500005];
struct l
{
    int tf,tp,w;
};
vector<l> e[505][1005];
vector<int> ci[505];
struct p
{
    int tx,ty,w;
    bool operator<(const p i)const
    {
        return w>i.w;
    }
};
bool vis[505][1005];
long long dis[505][1005];
long long dij(int u)
{
    priority_queue<p> p_q;
    for(int i=0;i<=n;i++)
    {
        for(int j:ci[i])
        {
            vis[i][j]=0;
            dis[i][j]=LLONG_MAX;
        }
    }
    p_q.push({0,u,0});
    while(!p_q.empty())
    {
        auto [X,Y,W]=p_q.top();
        p_q.pop();
        if(vis[X][Y])continue;
        vis[X][Y]=1;
        for(auto i:e[X][Y])
        {
            if(W+i.w<dis[i.tf][i.tp])
            {
                dis[i.tf][i.tp]=W+i.w;
                p_q.push({i.tf,i.tp,dis[i.tf][i.tp]});
            }
        }
    }
}
struct que
{
    int u,v,id;
    bool operator<(const que i)const
    {
        return u<i.u;
    }
}a[100005];
long long ans[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i],ci[0].push_back(i);
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        int a,b,t;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>t;
            if(j!=1)
            {
                e[i][a].push_back({i,b,0});
                e[i][b].push_back({i,a,0});
            }
            e[i][a].push_back({0,a,t});
            e[0][a].push_back({i,a,t});
            b=a;
            ci[i].push_back(a);
        }
    }
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        a[i]={u,v,i};
        //cout<<a[i].u<<' ';
        //cout<<u<<' '<<v<<'\n';
    }
    sort(a+1,a+q+1);
    for(int i=1;i<=q;)
    {
        dij(a[i].u);
        int u=a[i].u;
        while(a[i].u==u&&i<=q)
        {
            ans[a[i].id]=dis[0][a[i].v]+w[a[i].u]+w[a[i].v];
            //cout<<a[i].v<<' ';
            i++;
        }
        //cout<<i<<' ';
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
    return 0;
}
