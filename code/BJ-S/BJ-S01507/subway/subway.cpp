#include<bits/stdc++.h>
using namespace std;
const int N=500+10,M=5e5+10;
int c,n,m,d,q;
//描述地铁站
int w[M]/*地铁站入口到站厅的时间*/;
//描述线路
int k[N]/*经过的地铁站数量*/,a[N][M]/*经过的第j个地铁站编号*/,t[N][M]/*走到第j个站的站厅所需时间*/;
struct node
{
    int u,w;
    inline bool operator>(const node&nd)const
    {
        return w>nd.w;
    }
};
priority_queue<node,vector<node>,greater<node> > pq;
int vis[N+M],dis[N+M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    /*if(c>=7&&c<=11)*/
    {
        vector<pair<int,int> > g[m+5];
        for(int i=1;i<=n;i++)
        {
            cin>>k[i];
            for(int j=1;j<=k[i];j++)
            {
                cin>>a[i][j]>>t[i][j];
            }
            if(k[i]==1) continue;
            g[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
            g[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
            for(int j=1;j<=k[i];j++)
            {
                for(int k=1;k<j;k++)
                {
                    g[a[i][j]].push_back({a[i][k],t[i][j]+t[i][k]});
                    g[a[i][k]].push_back({a[i][j],t[i][j]+t[i][k]});
                }
            }
        }
        while(q--)
        {
            int s,t;
            cin>>s>>t;
            memset(dis,0x3f,sizeof(int)*(m+5));
            memset(vis,0,sizeof(bool)*(m+5));
            pq.push({s,0});
            vis[s]=1;
            dis[s]=0;
            while(!pq.empty())
            {
                int u=pq.top().u;
                pq.pop();
                for(const pair<int,int>&vw:g[u])
                {
                    int v=vw.first,w=vw.second;
                    if(dis[v]>dis[u]+w)
                    {
                        dis[v]=dis[u]+w;
                        pq.push({v,dis[v]});
                    }
                }
            }
            cout<<dis[t]+w[s]+w[t];
        }
    }
    return 0;
}
