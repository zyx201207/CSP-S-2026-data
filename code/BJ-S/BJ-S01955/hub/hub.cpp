#include <bits/stdc++.h>
using namespace std;
int C,t,n,k;
vector<int> e[1000005];
int dep[1000005];
int cnt[1000005];
int f[1000005];
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    f[u]=fa;
    cnt[dep[u]]++;
    for(int v:e[u])
        if(v!=fa)
            dfs(v,u);
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    while(dep[x]>dep[y])
        x=f[x];
    while(x!=y)
        x=f[x],y=f[y];
    return x;
}
int dis(int x,int y)
{
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
bool cho[1000005];
bool vis[1000005];
void ddd(int u)
{
    vis[u]=1;
    for(int v:e[u])
        if(cho[v]&&!vis[v])
            ddd(v);
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>C>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            e[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            e[u].push_back(v),e[v].push_back(u);
        }
        dfs(1,0);
        int ans=0x3f3f3f3f;
        for(int i=0;i<(1<<n);i++)
            if(__builtin_popcount(i)==k)
            {
                for(int j=1;j<=n;j++)
                    cho[j]=(bool)(i&(1<<(j-1))),vis[j]=false;
                int cc=0;
                for(int j=1;j<=n;j++)
                    if(cho[j]&&!vis[j])
                        ddd(j),cc++;
                if(cc==2)
                {
                    int mx=0;
                    for(int j=1;j<=n;j++)
                        if(!cho[j])
                        {
                            int mn=0x3f3f3f3f;
                            for(int k=1;k<=n;k++)
                                if(cho[k])
                                    mn=min(mn,dis(j,k));
                            mx=max(mx,mn);
                        }
                    ans=min(ans,mx);
                }
            }
        cout<<ans<<"\n";
    }
}
/*
//freopen("hub.in","r",stdin)
// freopen("hub.in","r",stdin)
hub hbu uhb ubh bhu buh
migrate migrat imgrate mirgate
subway suway wubsay subwa subwy
crystal crysta cystal crytsal cyrstal
feropen frepoen filereopen fflush fclose flcose
100+100+24+15
%%% sto otz osz szo
cout<<"Hello, world!"<<endl;
*/
