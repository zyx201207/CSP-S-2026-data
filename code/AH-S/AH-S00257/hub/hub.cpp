#include<bits/stdc++.h>
using namespace std;

const int N=15,INF=1e9;
int C,T;
int n,k,maxn,minn;
int a[N],dis[N];
bool vis[N];
vector <int> g[N];
void dfs(int u)
{
    for(auto v:g[u])
    {
        if(vis[v]) continue;
        vis[v]=1;
        dis[v]=min(dis[v],dis[u]+1);
        dfs(v);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(k==2)
        {
            minn=INF;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                {
                    maxn=0;
                    memset(vis,0,sizeof vis);
                    memset(dis,0x7f,sizeof dis);
                    vis[i]=vis[j]=1;
                    dis[i]=dis[j]=0;
                    dfs(i);dfs(j);
                    for(int k=1;k<=n;k++) maxn=max(maxn,dis[k]);
                    minn=min(minn,maxn);
                }
            cout<<minn<<"\n";
        }
        else cout<<"1\n";
    }
    return 0;
}
