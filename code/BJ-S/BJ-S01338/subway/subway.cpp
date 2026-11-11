#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5;
const int N=5e6;
int c,n,m,d,q,w[M],fa2[N],fa[N][35],tot,dis[N],dep[N],op,h[N];
int find(int x){
    if(x==fa2[x]) return x;
    return fa2[x]=find(fa2[x]);
}
void merge(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy) fa2[fx]=fy;
}
struct node{
    int v,w;
};
struct edge{
    int u,v,w;
};
bool cmp(edge x,edge y){
    return x.w<y.w;
}
vector<node> a[1000005];
edge g[1000005];
//厅i+n,站i
void kruskal(){
     for(int i=1;i<=op;i++){
        fa2[i]=i;
     }
     int cnt=0;
     for(int i=1;i<=tot;i++){
        int x=g[i].u;
        int y=g[i].v;
        int z=g[i].w;
        if(find(x)==find(y)) continue;
        merge(x,y);
        ++cnt;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
        if(cnt==op-1) return;
     }
}
void dfs(int u,int f){
    fa[u][0]=f;
    dep[u]=dep[f]+1;
    for(int i=0;i<a[u].size();i++){
        if(a[u][i].v==f) continue;
        dis[a[u][i].v]=dis[u]+a[u][i].w;
        dfs(a[u][i].v,u);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=dep[x]-dep[y];i;i-=(i&-i)){
        x=fa[x][(int)log2(i&-i)];
    }
    if(x==y) return x;
    for(int i=log2(m+m);i>=0;i--){
        if(fa[x][i]==fa[y][i]) continue;
        x=fa[x][i];
        y=fa[y][i];
    }
    return fa[x][0];
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    op=m*2;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int ls;
        for(int i=1;i<=k;i++){
            int id,t;
            cin>>id>>t;
            h[id]++;
            if(h[id]>1){
                op++;
                if(i!=1) g[++tot]={ls,op,0};
                g[++tot]={op,id+m,t};
                ls=op;
            }else{
                if(i!=1) g[++tot]={ls,id,0};
                g[++tot]={id,id+m,t};
                ls=id;
            }
        }
    }
    sort(g+1,g+tot+1,cmp);
    kruskal();
    dfs(1,1);
    for(int j=1;j<=log2(op);j++){
        for(int i=1;i<=op;i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int l=lca(x+m,y+m);
        cout<<dis[x+m]+dis[y+m]-2*dis[l]+w[x]+w[y]<<'\n';
    }
    return 0;
}
