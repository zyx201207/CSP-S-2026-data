#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
constexpr int maxn=1e6+5;
int c,T,n,k,U,V,du[maxn],l[maxn],cd[2];
bool vis[maxn],id[maxn];
std::vector<int>e[maxn];
void dfs(int u,int fa,bool x){
    ++cd[x];id[u]=x;
    for(int v:e[u]) if(v!=fa) dfs(v,u,x);
}
int main(){
    std::freopen("hub.in","r",stdin);
    std::freopen("hub.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>c>>T;
    while(T--){
        std::cin>>n>>k;
        for(int i=1;i<=n;++i) e[i].clear();
        for(int i=1;i<n;++i){
            int u,v;std::cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(k==n){std::cout<<"0\n";continue;}
        int ans=n-1;
        for(int U=1;U<=n;++U){
            for(int V:e[U]){
                if(U>V) continue;
                for(int i=1;i<=n;++i) vis[i]=false,du[i]=e[i].size();
                --du[U];--du[V];cd[0]=cd[1]=0;
                dfs(U,V,0);dfs(V,U,1);
                int hd=1,p=0,cc=0;
                for(int i=1;i<=n;++i) if(du[i]==1) vis[i]=1,l[++p]=i,cc+=!--cd[id[i]];
                for(int i=1;i<ans;++i){
                    if(n-p+cc<=k){ans=std::min(ans,i);break;}
                    int lp=p;
                    while(hd<=p){
                        int u=l[hd++];
                        for(int v:e[u]) if(!vis[v]&&!(u==U&&v==V||u==V&&v==U)&&--du[v]==1) vis[v]=1,l[++lp]=v,cc+=!--cd[id[v]];
                    }
                    p=lp;
                }
            }
        }
        std::cout<<ans<<'\n';
    }
    return 0;
}