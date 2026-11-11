#include <bits/stdc++.h>
using namespace std;
typedef long long ll
const int manx = 1e6+10;
int c,t,cnt,head[maxn],js,dfn[maxn],low[maxn],col,colour[maxn];
ll dist[maxn];
stack<int>;
struct Edge
{
    int to;
    int next;
}edge[maxn];
void add(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int u,int fa)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa)
        {
            continue;
        }
        dfs(v,u);
        dist[u]=dist[v]+1;
    }
}
void Tarjan(int u)
{
    dfn[u]=low[u]=++js;
    zhan.push(u);
    for(int i=1;i;i=edge[i].next)
    {
        int v.dege[i].yo;
        if(dfn[v]==0)
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(colour[v]==0)
        {
            low[u]=min(low[u],low[v]);
        }
        
    }
}
int main
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    whlie(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs(1,0);
        do{
            memset(a,0,sizeof(a));
            for(int i=1;i<=k;i++)
            {
                cout<<a[i]<<" ";
            }
            
        }whlie(next_permutation(a+1,a+1+k));
    }
    return 0;
}