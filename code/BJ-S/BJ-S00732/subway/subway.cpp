#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,Q,T[1000005],k[1000005],a[1000005],t[1000005],W[5005][5005],dis[1000005],ans,cnt;
vector<pair<int,int> > q[1000005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > p;
void dijkstra(int x)
{
    while(!p.empty())
    {
        p.pop();
    }
    p.push({0,x});
    W[x][x]=0;
    while(!p.empty())
    {
        int u=p.top().second;
        p.pop();
        for(auto i:q[u])
        {
            int v=i.first;
            int w=i.second;
            if(W[x][v]>W[x][u]+w)
            {
                W[x][v]=W[x][u]+w;
                p.push({W[x][v],v});
            }
        }
    }
}
int dijkstra2(int x,int y)
{
    while(!p.empty())
    {
        p.pop();
    }
    for(int i=1;i<=m;i++)
    {
        dis[i]=100000000000000005;
    }
    p.push({0,x});
    dis[x]=0;
    ans=100000000000000005;
    while(!p.empty())
    {
        int u=p.top().second;
        p.pop();
        for(auto i:q[u])
        {
            int v=i.first;
            int w=i.second;
            if(dis[v]>dis[u]+w&&(dis[u]+w)<ans-cnt)
            {
                dis[v]=dis[u]+w;
                if(v==y)
                {
                    ans=dis[v];
                }
                p.push({dis[v],v});
            }
        }
    }
    return dis[y];
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)
    {
        cin>>T[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k[i];j++)
        {
            for(int l=j+1;l<=k[i];l++)
            {
                q[a[j]].push_back({a[l],t[j]+t[l]});
                q[a[l]].push_back({a[j],t[j]+t[l]});
                //cout<<a[j]<<" "<<a[l]<<" "<<t[j]+t[l]<<"\n";
            }
        }
    }
    if(c>=12&&c<=15)
    {
        while(Q--)
        {
            int x,y;
            cin>>x>>y;
            cnt=1000000000000005;
            for(auto i:q[y])
            {
                cnt=min(cnt,i.second);
            }
            cout<<dijkstra2(x,y)+T[x]+T[y]<<"\n";
        }
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            W[i][j]=100000000000000005;
        }
    }
    for(int i=1;i<=m;i++)
    {
        dijkstra(i);
    }
    while(Q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<T[x]+T[y]+W[x][y]<<"\n";
    }
    return 0;
}
