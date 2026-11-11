#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,cnt;
int w[500005];
int dis[505][505];
int dis1[500505];
struct node
{
    int id,x;
};
vector<node> a[500005];
bool operator<(node x,node y)
{
    return x.x>y.x;
}
void bfs(int s)
{
    priority_queue<node> q; 
    for(int i=1;i<=cnt;i++)dis1[i]=1e9;
    q.push({s,0});
    dis1[s]=0;
    while(!q.empty())
    {
        int tx=q.top().id,ty=q.top().x;
        q.pop();
        if(ty!=dis1[tx])continue;
        for(node i:a[tx])
        {
            if(dis1[i.id]>dis1[tx]+i.x)
            {
                dis1[i.id]=dis1[tx]+i.x;
                q.push({i.id,dis1[i.id]});
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        dis[s][i]=dis1[i];
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    cnt=m;
    for(int i=1;i<=n;i++)
    {
        int k,last=0;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int id,t;
            cin>>id>>t;
            a[id].push_back({++cnt,t});
            a[cnt].push_back({id,t});
            if(j!=1)a[last].push_back({cnt,0});
            if(j!=1)a[cnt].push_back({last,0});
            last=cnt;
        }
    }
    for(int i=1;i<=m;i++)
    {
        bfs(i);
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}