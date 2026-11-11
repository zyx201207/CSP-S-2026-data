#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int c,n,m,d,q;
vector<PII> e[50000005];
int dis[5000005];
priority_queue<PII,vector<PII>,greater<PII>> pq;
int dijkstra(int S,int E)
{
    int i;
    pq.push({0,S});//first->distance, second->position
    for(i=1;i<=2*m+n+1;i++)
    {
        dis[i]=INT_MAX;
    }
    dis[S]=0;
    while(!pq.empty())
    {
        int cd=pq.top().first;
        int cp=pq.top().second;
        pq.pop();
        if(cd!=dis[cp])
        {
            continue;
        }
        for(auto i:e[cp])
        {
            int v=i.first,dist=i.second;
            if(cd+dist<dis[v])
            {
                dis[v]=cd+dist;
                pq.push({dis[v],v});
            }
        }
    }
    return dis[E];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j;
    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        e[2*i-1].push_back({2*i,x});
        e[2*i].push_back({2*i-1,x});
    }
    for(i=1;i<=n;i++)
    {
        int station;
        cin>>station;
        for(j=1;j<=station;j++)
        {
            int x,dis;
            cin>>x>>dis;
            e[2*m+i].push_back({2*x,dis});
            e[2*x].push_back({2*m+i,dis});
        }
    }
    for(i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<dijkstra(2*x-1,2*y-1)<<endl;
    }
    return 0;
}
