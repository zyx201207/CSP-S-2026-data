#include<iostream>
#include<vector>
using namespace std;
constexpr int N=1e6+5;
int n,k;
struct SET{
    int fa[N];
    void init(int n){
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        int u=find(x),v=find(y);
        if(u!=v) fa[v]=u;
    }
}st;
vector<int> g[N];
int ans;
int d[N],fa[N][21];
void dfs(int u,int fno=0){
    d[u]=d[fno]+1;
    fa[u][0]=fno;
    for(int j=0;j<20;j++) fa[u][j+1]=fa[fa[u][j]][j];
    for(auto v:g[u]) if(v!=fno) dfs(v,u);
}
pair<int,int> e[N];
int lca(int u,int v){
    if(d[u]>d[v]) swap(u,v);
    for(int j=20;j>=0;j--) if(d[fa[v][j]]>=d[u]) v=fa[v][j];
    if(u==v) return u;
    for(int j=20;j>=0;j--) if(fa[u][j]!=fa[v][j]) u=fa[u][j],v=fa[v][j];
    return fa[u][0];
}
int dis(int i,int j){
    int l=lca(i,j);
    return d[i]-d[l]+d[j]-d[l];
}
bool f[N];
void dfs1(int now,int cnt){
    if(cnt>k) return;
    if(now>n){
        if(cnt!=k) return;
        st.init(n);
        for(int i=1;i<n;i++){
            if(f[e[i].first]&&f[e[i].second]){
                st.merge(e[i].first,e[i].second);
            }
        }
        int tot=0;
        for(int i=1;i<=n;i++) if(f[i]&&st.fa[i]==i) tot++;
        if(tot>2) return;
        int mx=0;
        for(int i=1;i<=n;i++){
            if(!f[i]){
                int mn=2e9;
                for(int j=1;j<=n;j++){
                    if(f[j]){
                        mn=min(mn,dis(i,j));
                    }
                }
                mx=max(mx,mn);
            }
        }
        ans=min(ans,mx);
        return;
    }
    f[now]=true;
    dfs1(now+1,cnt+1);
    f[now]=false;
    dfs1(now+1,cnt);
}
void work(){
    ans=2e9;
    cin>>n>>k;
    for(int i=1;i<n;i++) g[i].resize(0);
    for(int i=1;i<n;i++){
        cin>>e[i].first>>e[i].second;
        g[e[i].first].push_back(e[i].second);
        g[e[i].second].push_back(e[i].first);
    }
    dfs(1);
    dfs1(1,0);
    cout<<ans<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    for(cin>>c>>t;t;t--) work();
    return 0;
}