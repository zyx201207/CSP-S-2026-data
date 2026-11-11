#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int n,k;
namespace Graph{
    const int N=100005;
    vector<int>V;
    vector<int>e[N];
    void clear(){
        for(int x:V) e[x].clear();
        V.clear();
    }
    void add(int x){
        V.push_back(x);
    }
    void adde(int x,int y){
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int dep[N],fa[N];
    void dfs(int u,int pre){
        dep[u]=dep[pre]+1;
        fa[u]=pre;
        for(int v:e[u]){
            if(v==pre) continue;
            dfs(v,u);
        }
    }
    int mx[N];
    void dfs2(int u,int pre){
        mx[u]=1;
        for(int v:e[u]){
            if(v==pre) continue;
            dfs2(v,u);
            mx[u]=max(mx[u],mx[v]+1);
        }
    }
    int w[N];
    void calc(){
        int u=V.front();
        dfs(u,0);
        for(int x:V)
            if(dep[x]>dep[u]) u=x;
        dfs(u,0);
        int v=u;
        for(int x:V)
            if(dep[x]>dep[v]) v=x;
        if(dep[v]&1){
            int d=dep[v]/2;
            for(int i=1;i<=d;i++)
                v=fa[v];
            dfs2(v,0);
        }
        else{
            int d=dep[v]/2-1;
            for(int i=1;i<=d;i++) v=fa[v];
            dfs2(v,fa[v]);
            dfs2(fa[v],v);
        }
        int m=V.size();
        for(int i=0;i<m;i++)
            w[i]=mx[V[i]];
        w[m]=0;
        sort(w,w+m+1);
        reverse(w,w+m+1);
    }
}
namespace sub1{
    const int N=4005;
    vector<int>e[N];
    int f[N],g[N];
    void dfs(int u,int pre){
        Graph::add(u);
        for(int v:e[u]){
            if(v==pre) continue;
            Graph::adde(u,v);
            dfs(v,u);
        }
    }
    void solve(){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            e[i].clear();
        for(int i=1,x,y;i<n;i++){
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        int res=n+1;
        Graph::clear();
        for(int i=1;i<=n;i++){
            Graph::add(i);
            for(int v:e[i]) if(v>i) Graph::adde(i,v);
        }
        Graph::calc();
        res=Graph::w[k];
        for(int u=1;u<=n;u++)
            for(int v:e[u]){
                if(v<u) continue;
                Graph::clear();
                dfs(u,v);
                int nx=Graph::V.size();
                Graph::calc();
                for(int i=1;i<=nx;i++)
                    f[i]=Graph::w[i];
                Graph::clear();
                dfs(v,u);
                int ny=Graph::V.size();
                Graph::calc();
                for(int i=1;i<=ny;i++)
                    g[i]=Graph::w[i];
                for(int i=1;i<k;i++)
                    if(i<=nx&&k-i<=ny)
                        res=min(res,max(f[i],g[k-i]));
            }
        printf("%d\n",res);
    }
    void Main(){
        int t;
        cin>>t;
        for(;t;--t) solve();
    }
}
namespace sub2{
    const int N=100005;
    int dfn[N],dep[N],fa[N],rnk[N],siz[N];
    int dfncnt;
    vector<int>e[N];
    int st[17][N],lg[N];
    int mymin(int u,int v){
        return dep[u]<dep[v]?u:v;
    }
    void dfs(int u,int pre){
        dfn[u]=++dfncnt;
        rnk[dfncnt]=u;
        dep[u]=dep[pre]+1;
        fa[u]=pre;
        siz[u]=1;
        for(int v:e[u]){
            if(v==pre) continue;
            dfs(v,u);
            siz[u]+=siz[v];
        }
    }
    void build(){
        dfncnt=0;
        dfs(1,0);
        for(int i=1;i<=n;i++)
            st[0][dfn[i]]=i;
        for(int i=2;i<=n;i++)
            lg[i]=lg[i>>1]+1;
        for(int j=1;j<=lg[n];j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                st[j][i]=mymin(st[j-1][i],st[j-1][i+(1<<(j-1))]);
    }
    int query(int l,int r){
        int k=lg[r-l+1];
        return mymin(st[k][l],st[k][r-(1<<k)+1]);
    }
    int lca(int u,int v){
        if(u==v) return u;
        if(dfn[u]>dfn[v]) swap(u,v);
        return fa[query(dfn[u]+1,dfn[v])];
    }
    int dis(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
    struct node{
        int u,v,d;
        friend node merge(const node& x,const node& y){
            if(x.u==0) return y;
            if(y.u==0) return x;
            node res=x;
            if(y.d>x.d) res=y;
            int cur=dis(x.u,y.u);
            if(cur>res.d) res={x.u,y.u,cur};
            cur=dis(x.u,y.v);
            if(cur>res.d) res={x.u,y.v,cur};
            cur=dis(x.v,y.u);
            if(cur>res.d) res={x.v,y.u,cur};
            cur=dis(x.v,y.v);
            if(cur>res.d) res={x.v,y.v,cur};
            return res;
        }
        void add(int x){
            if(u==0){
                u=x,v=x,d=0;
                return;
            }
            int nx=dis(u,x),ny=dis(v,x);
            if(nx<ny) swap(nx,ny),swap(u,v);
            if(nx>d) v=x,d=nx;
        }
    };
    node pre[N],suf[N];
    node sub[17][N];
    void solve(){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            e[i].clear();
        for(int i=1,x,y;i<n;i++){
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        int res=n+1;
        Graph::clear();
        for(int i=1;i<=n;i++){
            Graph::add(i);
            for(int v:e[i]) if(v>i) Graph::adde(i,v);
        }
        Graph::calc();
        res=Graph::w[k];
        build();
        pre[0]={0,0,0};
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1];
            pre[i].add(rnk[i]);
        }
        suf[n+1]={0,0,0};
        for(int i=n;i>=1;i--){
            suf[i]=suf[i+1];
            suf[i].add(rnk[i]);
        }
        for(int i=1;i<=n;i++)
            sub[0][i]={rnk[i],rnk[i],0};
        for(int j=1;j<=lg[n];j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                sub[j][i]=merge(sub[j-1][i],sub[j-1][i+(1<<(j-1))]);
        for(int i=2;i<=n;i++){
            node cur;
            cur=merge(pre[dfn[i]-1],suf[dfn[i]+siz[i]]);
            int now=(cur.d+1)/2;
            int k=lg[siz[i]];
            cur=merge(sub[k][dfn[i]],sub[k][dfn[i]+siz[i]-(1<<k)]);
            now=max(now,(cur.d+1)/2);
            res=min(res,now);
        }
        printf("%d\n",res);
    }
    void Main(){
        int t;
        cin>>t;
        for(;t;--t) solve();
    }
}
namespace sub3{
    void solve(){
        scanf("%d%d",&n,&k);
        for(int i=1,x,y;i<n;i++)
            scanf("%d%d",&x,&y);
        int m=(n-1)/2;
        if(k==n){
            printf("0\n");
            return;
        }
        if(k>=m){
            printf("1\n");
            return;
        }
        int res=(m-k+2+1)/2;
        for(int i=1;i<=m;i++)
            for(int j=max(1,i-1);j<=min(m,i+1);j++){
                int x=i,y=m+1-j;
                int cur=y-x-(k-2);
                if(cur<=0) continue;
                res=min(res,max({i,j,(cur+1)/2+1}));
            }
        printf("%d\n",res);
    }
    void Main(){
        int t;
        cin>>t;
        for(;t;--t) solve();
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c;
    cin>>c;
    if(c<=10) return sub1::Main(),0;
    if(c<=12) return sub2::Main(),0;
    if(c<=14) return sub3::Main(),0;
}