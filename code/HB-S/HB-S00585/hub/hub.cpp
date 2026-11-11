#include<iostream>
using namespace std;
const int N=1e6+5;
struct edge
{
    int to,nxt;
}e[N*2];
int head[N],ed,dis[1005][1005],rt,cho[N],vis[N],p[N];
int n,k,ans;
void add(int u,int v)
{
    e[++ed].to=v;
    e[ed].nxt=head[u];
    head[u]=ed;
    return ;
}
void dfs(int u,int fa)
{
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
        dis[rt][v]=dis[rt][u]+1;
        dfs(v,u);
    }
    return ;
}
void dfs1(int u,int fa)
{
    if(!cho[u])
        return ;
    vis[u]=1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
        dfs1(v,u);
    }
    return ;
}
void calc()
{
    int cnt=0;
    for(int i=1;i<=n;i++)
        vis[i]=0;
    for(int i=1;i<=k;i++)
        if(!vis[p[i]])
        {
            cnt++;
            dfs1(p[i],0);
        }
    if(cnt>2)
        return ;
    int d=0,d1;
    for(int i=1;i<=n;i++)
    {
        d1=N;
        for(int j=1;j<=k;j++)
            d1=min(d1,dis[i][p[j]]);
        d=max(d,d1);
    }
    ans=min(ans,d);
    return ;
}
void dfs2(int cur,int lst)
{
    if(cur>k)
    {
        calc();
        return ;
    }
    for(int i=lst+1;i<=n;i++)
    {
        cho[i]=1;
        p[cur]=i;
        dfs2(cur+1,i);
        cho[i]=0;
    }
    return ;
}
void solve()
{
    ans=N;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int d=0;
            for(int x=1;x<=n;x++)
                d=max(d,min(dis[i][x],dis[j][x]));
            ans=min(ans,d);
        }
    cout<<ans<<"\n";
    return ;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T,u,v;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        ed=0;
        for(int i=1;i<=n;i++)
            head[i]=0;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        for(int i=1;i<=n;i++)
        {
            rt=i;
            dis[i][i]=0;
            dfs(i,0);
        }
        if(c==7)
        {
            solve();
            continue;
        }
        ans=N;
        dfs2(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
