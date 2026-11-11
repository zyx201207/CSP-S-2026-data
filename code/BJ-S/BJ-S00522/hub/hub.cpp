#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const int inf=1e9;
int c,t;
int n,k,ans;
bool a[maxn];
int f[maxn];
int b[maxn];
int dis[maxn];
bool h[1005][1005];
vector<int>g[maxn];
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    f[fx]=fy;
}
void dfs1(int x,int y,int z)
{
    dis[x]=min(dis[x],z);
    for(int i=0;i<g[x].size();i++)
    {
        int w=g[x][i];
        if(w==y) continue;
        dfs1(w,x,z+1);
    }
}
void dfs(int x,int y)
{
    if(x==n+1)
    {
        if(y==0)
        {
            for(int i=1;i<=k;i++)
                f[i]=i;
            int tot=0;
            for(int i=1;i<=n;i++)
                if(a[i])
                    b[++tot]=i;//,cout<<b[tot]<<" ";
            //cout<<"\n";
            for(int i=1;i<=k;i++)
                for(int j=i+1;j<=k;j++)
                    if(h[b[i]][b[j]])
                        merge(i,j);
            int res=0;
            for(int i=1;i<=k;i++)
                if(find(i)==i)
                    res++;
            if(res>2) return ;
            for(int i=1;i<=n;i++)
                dis[i]=inf;
            for(int i=1;i<=k;i++)
                dfs1(b[i],0,0);
            int ans1=0;
            for(int i=1;i<=n;i++)
                ans1=max(ans1,dis[i]);
            ans=min(ans,ans1);
        }
        return ;
    }
    if(y) a[x]=1,dfs(x+1,y-1);
    a[x]=0,dfs(x+1,y);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ans=inf;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                h[i][j]=0;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            h[u][v]=h[v][u]=1;
        }
        dfs(1,k);
        cout<<ans<<"\n";
    }
    return 0;
}

