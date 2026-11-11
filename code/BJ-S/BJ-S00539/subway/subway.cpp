#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
typedef long long ll;
const int N=5e5+505;
int c,n,m,d,T,dis[N],wi[N],dep[N],st[N][20];
struct dat{
    int v,w;
};
vector<dat>g[N];
struct edge{
    int u,v,w;
    bool operator<(const edge&b)const{
        return w<b.w;
    }
}e[N];
int f[N];
int find(int u){
    if(u==f[u])return u;
    return f[u]=find(f[u]);
}
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    st[u][0]=p;
    for(int i=1;i<=19;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(auto i:g[u]){
        int v=i.v,w=i.w;
        if(v==p)continue;
        dis[v]=dis[u]+w;
        dfs(v,u);
    }
}
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    if(dep[a]!=dep[b]){
        for(int i=19;i>=0;i--){
            int c=st[a][i];
            if(dep[c]>=dep[b])a=c;
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        int u=st[a][i],v=st[b][i];
        if(u!=v)a=u,b=v;
    }
    return st[a][0];
}
int getdis(int a,int b){
    int c=lca(a,b);
    return dis[a]+dis[b]-2ll*dis[c];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>T;
    int cnte=0;
    for(int i=1;i<=m;i++)cin>>wi[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            e[++cnte]={a,i+m,t};
        }
    }
    sort(e+1,e+cnte+1);
    iota(f+1,f+n+m+1,1);
    for(int i=1;i<=cnte;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int ui=find(u),vi=find(v);
        if(ui!=vi){
            f[ui]=vi;
            g[u].pb({v,w});
            g[v].pb({u,w});
            //cout<<u<<" "<<v<<" "<<w<<"\n";
        }
    }
    dfs(1,0);
    for(int i=1;i<=T;i++){
        int x,y;
        cin>>x>>y;
        cout<<wi[x]+wi[y]+getdis(x,y)<<"\n";
    }
    return 0;
}
