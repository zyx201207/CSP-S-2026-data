#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge
{
    int w,v;
    bool operator>(const edge& a)const
    {
        return w>a.w;
    }
    bool operator<(const edge& a)const
    {
        return w<a.w;
    }
};
struct question
{
    int a1,b1,fir,ans;
}que[100005];
int ww[500005];
int k[505];
vector<edge>mapp[600000];
int mapp_size;
int cmp(question a,question b)
{
    return a.a1<b.a1;
}
int cmp1(question a,question b)
{
    return a.fir<b.fir;
}
int dis[600005];
int vis[600005];
void dijkstra(int a)
{
    priority_queue<edge,vector<edge>,greater<edge>>q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[a]=0;
    q.push({0,a});
    while(!q.empty())
    {
        int u=q.top().v;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<mapp[u].size();i++)
        {
            int v1=mapp[u][i].v,w1=mapp[u][i].w;
            if(dis[u]+w1<dis[v1])
            {
                dis[v1]=dis[u]+w1;
                q.push({dis[v1],v1});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q,t;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>ww[i];
    mapp_size=m;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>k[i];
        if(k[i]==2)
        {
            int b,t2;
            cin>>a>>t>>b>>t2;
            mapp[a].push_back({t+t2,b});
            mapp[b].push_back({t+t2,a});
            continue;
        }
        mapp_size++;
        for(int j=1;j<=k[i];j++)
        {
            cin>>a>>t;
            mapp[mapp_size].push_back({t,a});
            mapp[a].push_back({t,mapp_size});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        que[i]={a,b,i,-1};
    }
    sort(que+1,que+1+q,cmp);
    for(int i=1;i<=q;i++)
    {
        if(i==0||que[i].a1!=que[i-1].a1)
            dijkstra(que[i].a1);
        que[i].ans=dis[que[i].b1]+ww[que[i].a1]+ww[que[i].b1];
    }
    sort(que+1,que+1+q,cmp1);
    for(int i=1;i<=q;i++)
        cout<<que[i].ans<<'\n';
    return 0;
}
