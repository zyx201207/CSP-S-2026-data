#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,D=25;
int c,n,m,q,d,w[N],dis[N][D];
bool vis[N][D];
struct Edge{
    int u,idx,num;
};
struct Side{
    int u,idx,Dis;
    bool operator<(const Side &oth)const{
        return Dis>oth.Dis;
    }
};
vector<Edge>con[N][D];
priority_queue<Side>Q;
void GetData()
{
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1,u,Cost,v=-1;j<=k;j++,v=u)
        {
            cin>>u>>Cost;
            if(v!=-1)
            {
                con[u][i].push_back({v,i,0});
                con[v][i].push_back({u,i,0});
            }
            con[u][0].push_back({u,i,Cost});
            con[u][i].push_back({u,0,Cost});
        }
    }
}
void Init(int s)
{
    while(!Q.empty()) Q.pop();
    for(int i=1;i<=m;i++)
        for(int j=0;j<=d;j++)
            vis[i][j]=0,dis[i][j]=1e18;
    dis[s][0]=0;
    Q.push({s,0,0});
}
void Dij()
{
    int s,t;
    cin>>s>>t;
    Init(s);
    while(!Q.empty())
    {
        int u=Q.top().u,idx=Q.top().idx,Dis=Q.top().Dis;
        Q.pop();
        if(!vis[u][idx])
        {
            vis[u][idx]=1;
            for(Edge v:con[u][idx])
                if(dis[v.u][v.idx]>dis[u][idx]+v.num)
                {
                    dis[v.u][v.idx]=dis[u][idx]+v.num;
                    if(!vis[v.u][v.idx]) Q.push({v.u,v.idx,dis[v.u][v.idx]});
                }
        }
    }
    int Ans=w[s]+w[t]+dis[t][0];
    cout<<Ans<<'\n';
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    GetData();
    while(q--) Dij();
}
