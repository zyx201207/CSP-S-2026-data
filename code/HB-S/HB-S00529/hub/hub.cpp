#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int l[N];
int r[N];
int mx[N];
vector<int>graph[N];
int dis[N];
void dfs1(int u,int fa)
{
    for(int v:graph[u])
    {
        if(v==fa)
        {
            continue;
        }
        dis[v]=dis[u]+1;
         dfs1(v,u);
    }
}
void dfs2(int u,int fa)
{
    for(int v:graph[u])
    {
        if(v==fa)
        {
            continue;
        }
        l[v]=l[u]+1;
        dfs2(v,u);
    }
}
void dfs3(int u,int fa)
{
    for(int v:graph[u])
    {
        if(v==fa)
        {
            continue;
        }
        r[v]=r[u]+1;
        dfs3(v,u);
    }
}
int main()
{
    freopen("hub1.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    int n;
    int k;
    int u,v;
    while(t--)
    {
        cin>>n>>k;
        int id=0;
        ll v=0;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        memset(dis,0,sizeof(dis));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        dfs1(1,0);
        for(int i=1;i<=n;i++)
        {
            if(dis[i]>v)
            {
                id=i;
                v=dis[i];
            }
        }
        dis[id]=0;
        dfs1(id,0);
        int id2=0;
        v=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]>v)
            {
                id2=i;
                v=dis[i];
            }
        }
        dfs2(id,0);
        dfs3(id2,0);
        for(int i=1;i<=n;i++)
        {
            mx[i]=max(l[i],r[i]);
        }
        sort(mx+1,mx+1+n);
        cout<<mx[2]<<"\n";
    }
    return 0;
}