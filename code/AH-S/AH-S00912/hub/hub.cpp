#include <bits/stdc++.h>
using namespace std;

const int N=25;
int dis[N][N],dep[N],f[N];
bool vis[N];
vector<int>a[N];
struct DSU{
    int n,f[N];
    void init(){for(int i=1;i<=n;i++) f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    void merge(int u,int v){
        int x=find(u),y=find(v);
        if (x!=y) f[x]=y;
    }
}dsu;
int getdis(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    int ans=0;
    while(dep[u]>dep[v]) ans++,u=f[u];
    if (u==v) return ans;
    while(u!=v) ans+=2,u=f[u],v=f[v];
    return ans+2;
}
void dfs(int w,int fa){
    dep[w]=dep[fa]+1;f[w]=fa;
    for(int i=0;i<a[w].size();i++){
        if (a[w][i]==fa) continue;
        dfs(a[w][i],w);
    }
}
void work(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) a[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=getdis(i,j);
        }
    }
    dsu.n=n;
    int ans=1e9+7;
    for(int i=0;i<(1<<n);i++){
        memset(vis,0,sizeof(vis));
        int cnt=0;vector<int>d;d.clear();
        for(int j=0;j<n;j++) if (i&(1<<j)) cnt++,vis[j+1]=1,d.push_back(j+1);
        if (cnt==k){
            dsu.init();
            for(int j=0;j<d.size();j++){
                for(int z=0;z<a[d[j]].size();z++){
                    if (vis[a[d[j]][z]])dsu.merge(d[j],a[d[j]][z]);
                }
            }
            memset(vis,0,sizeof(vis));
            for(int j=0;j<d.size();j++) vis[dsu.find(d[j])]=1;
            int g=0;
            for(int j=1;j<=n;j++) if (vis[j]) g++;
            if (g>2) continue;
            int sum=0;
            for(int z=1;z<=n;z++){
                int rtp=1e9+7;
                for(int rp=0;rp<d.size();rp++){
                    rtp=min(rtp,dis[d[rp]][z]);
                }
                sum=max(sum,rtp);
            }
            ans=min(ans,sum);
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) work();
    return 0;
}