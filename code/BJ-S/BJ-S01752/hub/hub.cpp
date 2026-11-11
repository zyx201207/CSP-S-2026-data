#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
vector<int>e[15];
int a[15];
int vis[15];
int viss[15];
int dis[15][15];
int di[15][15];
int maxx[15];
void dfs(int u)
{
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(vis[v]==1 || a[v]==0)continue;
        vis[v]=1;
        dfs(v);
    }
}
struct edge{
    int v,w;
};
struct node{
    int uu,dis;
    bool operator<(const node& x)const
    {
        return x.dis<dis;
    }
};
priority_queue<node,vector<node>,less<node> >q;
inline void dijkstra(int st)
{
    while(!q.empty())q.pop();
    q.push((node){st,0});
    for(int i=1;i<=n;i++)
    {
        dis[st][i]=1e17;
        viss[i]=0;
    }
    dis[st][st]=0;
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        int uu=t.uu;
        if(viss[uu]==1)continue;
        viss[uu]=1;
        for(int i=0;i<e[uu].size();i++)
        {
            int v=e[uu][i];
            if(viss[v]==1)continue;
            if(dis[st][v]>dis[st][uu]+1)
            {
                dis[st][v]=dis[st][uu]+1;
                q.push((node){v,dis[st][v]});
            }
        }
    }
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        int minn=1e18;
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%lld%lld",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int o=pow(2,n);
        for(int f=0;f<o;f++)
        {
            int r=f;
            int cntt=0;
            int cnt=0;
            int sum=0;
            int maxxx=-1e18;
            for(int i=1;i<=n;i++)
            {
                maxx[i]=1e18;
                a[i]=0;
            }
            while(r)
            {
                a[++cnt]=r%2;
                r/=2;
                cntt+=a[cnt];
            }
            if(cntt!=k)continue;
            for(int i=1;i<=cnt;i++)
            {
                if(a[i]==1 && vis[i]==0)
                {
                    vis[i]=1;
                    dfs(i);
                    sum++;
                }
                for(int j=1;j<=n;j++)if(dis[i][j]==0)dis[i][j]=1e18;
            }
            if(sum>2)continue;
            for(int i=1;i<=n;i++)
            {
                dijkstra(i);
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(dis[i][j]!=1e18 && a[j]==1)maxx[i]=min(maxx[i],dis[i][j]);
                    //cout<<dis[i][j]<<" ";
                }
                //cout<<endl;
                vis[i]=0;
                maxxx=max(maxxx,maxx[i]);
            }
            //cout<<f<<" "<<cntt<<"   ";
            for(int i=1;i<=n;i++)
            {
                //cout<<a[i]<<" ";
                a[i]=0;
            }
            //cout<<"   "<<maxxx;
            //cout<<endl;
            minn=min(minn,maxxx);
        }
        printf("%lld\n",minn);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                di[i][j]=0;
            }
            a[i]=0;
        }
        for(int i=1;i<=n;i++)e[i].clear();
    }
    return 0;
}
