#include <bits/stdc++.h>
using namespace std;
const int N=3e5+77;
vector<int> g[N];
vector<int> v;
long long dis[N],d[N];
bool vis[N];
queue<int> q;
priority_queue<pair<long long,int> > pq;
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(int z : g[u])
        {
            int flag=false;
            for(int x : v)
            {
                if(z==x) flag=true;
            }
            if(!flag) continue;
            if(dis[u]+1<dis[z])
            {
                dis[z]=dis[u]+1;
                pq.push({-dis[z],z});
            }
        }
    }
}
void dfs(int u,int f)
{
    vis[u]=true;
    int flag=false;
    for(int z : g[u])
    {
        if(z==f || vis[u]) continue;
        int f=false;
        for(int x : v)
        {
            if(x==z)
            {
                flag=true;
            }
        }
        if(!flag) continue;
        flag=true;
        dfs(z,u);
    }
    if(!flag) return;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            while(!g[i].empty()) g[i].pop_back();
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long minn=1e18;
        for(int i=1;i<=(1<<(n-1));i++)
        {
            memset(d,0x3f,sizeof d);
            memset(vis,false,sizeof vis);
            while(!v.empty()) v.pop_back();
            int tmp=i;
            int cnt=0;
            while(tmp)
            {
                cnt++;
                tmp&=(tmp-1);
            }
            if(cnt!=k) continue;
            for(int j=1;j<n;j++)
            {
                int tmp=i;
                int flag=(1<<j);
                if((tmp&flag)==flag)
                {
                    v.push_back(j);
                }
            }
            bool flag=false;
            dfs(v[1],0);
            for(int x : v)
            {
                if(!vis[x])
                {
                    dfs(x,0);
                    for(int z : v)
                    {
                        if(!vis[z])
                        {
                            flag=true;
                            break;
                        }
                    }
                }
            }
            if(flag) continue;
            long long maxx=-1e18;
            for(int j=1;j<=n;j++)
            {
                dijkstra(j);
                for(int l : v)
                {
                    d[j]=min(d[j],dis[l]);
                }
                int flag=false;
                for(int l : v)
                {
                    if(j==l)
                    {
                        d[j]=0;
                    }
                }
                maxx=max(maxx,d[j]);
            }
            minn=min(minn,maxx);
        }
        cout<<minn<<'\n';
    }
    return 0;
}
