#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define maxn 501009
#define pii pair<int,int> 


int c,n,m,d,q;
int w[maxn];
vector<pii> e[maxn];


int dis2[510][510];
vector<pii> g[600];
int dis[600],vis[600];
priority_queue<pii ,vector< pii >,greater< pii > >que;

//g++ subway.cpp -o subway -o2 -std=c++14 -static -Wall -Wextra -Wshadow -Wconversion

int subwid(int x){return m+x;}

void dijkstra(int st)
{
    for(int i=1;i<=509;i++) dis[i]=1000000000000000,vis[i]=0;
    while(!que.empty()) que.pop();
    dis[st]=0;
    que.push({0,st});
    while(!que.empty())
    {
        int now=que.top().second;
        que.pop();
        if(vis[now]==1) continue;
        vis[now]=1;
        for(int i=0;i<(int)g[now].size();i++)
        {
            int to=g[now][i].first,payw=g[now][i].second;
            if(dis[to]>dis[now]+payw)
            {
                dis[to]=dis[now]+payw;
                que.push({dis[to],to});
            }
        }
    }
    return ;
}

signed main()
{



    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

 ios::sync_with_stdio(0),cin.tie(0);   

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        for(int j=1,u,v;j<=k;j++)
        {
            cin>>u>>v;
            e[u].push_back({subwid(i),v});
            e[subwid(i)].push_back({u,v});
        }
    }

    for(int i=1;i<=m;i++)
    {
        
        for(int j=0;j<(int)e[i].size();j++)
        {
            for(int k=0;k<(int)e[i].size();k++)
            {
                if(j==k) continue;
                g[e[i][j].first-m].push_back({e[i][k].first-m,e[i][j].second+e[i][k].second});
            }
        }
        
    }


    for(int i=1;i<=n;i++)
    {
        dijkstra(i);
        for(int j=1;j<=n;j++)
        {
            if(j==i) dis2[i][j]=0,dis2[j][i]=0;
            dis2[i][j]=dis[j];
            dis2[j][i]=dis[j];
        }
    }

    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        int ans=1000000000000000000;
        int szx=e[x].size(),szy=e[y].size();
        for(int xx=0;xx<szx;xx++)
        {
            for(int yy=0;yy<szy;yy++)
            {
                int now1=e[x][xx].first;
                int now2=e[y][yy].first;
                ans=min(ans,dis2[now1-m][now2-m]+e[x][xx].second+e[y][yy].second);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;   
}