#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1005;
const int Q=1e5+5;
const int inf=1e9+7;
#define pii pair<int,int>
#define piii pair<int,pii>
int c,n,m,d,q;
struct edge
{
    int v,d;
};
vector<edge>e[N];
int dis[N],w[N],vis[N];
void dij(int s)
{
    for(int i=1;i<=m+n;i++)dis[i]=inf;
    for(int i=1;i<=m+n;i++)vis[i]=0;
    priority_queue<pii>q;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        int x=q.top().second;q.pop();
        if(vis[x])continue;
        for(edge t:e[x])
        {
            int y=t.v,z=t.d;
            if(dis[y]>dis[x]+z)
            {
                dis[y]=dis[x]+z;
                q.push({-dis[y],y});
            }
        }
    }
}
piii que[N];
int ba[N],ans[N];
int la;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++)
    {
        int k;cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;cin>>x>>y;
            e[i+n].push_back({x,y});
            e[x].push_back({i+n,y});
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>que[i].first>>que[i].second.first;
        que[i].second.second=i;
    }
    sort(que+1,que+1+q);
    for(int i=1;i<=q;i++)ba[que[i].second.second]=i;
    for(int i=1;i<=q;i++)
    {
        int x=que[i].first,y=que[i].second.first;
        if(x!=la)dij(x);
        ans[i]=dis[y]+w[x]+w[y];
    }
    for(int i=1;i<=q;i++)cout<<ans[ba[i]]<<'\n';
    return 0;
}
/*
rp++
sto sto ccf orz orz
rp++

qiuqiule qwq
buyaobaoling awa
*/