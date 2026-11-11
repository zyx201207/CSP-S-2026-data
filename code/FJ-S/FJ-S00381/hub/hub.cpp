#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=1e6+5,INF=1e9;
int c,t,n,k,tot;
int ls[N];
struct eg{
    int u,v,pr;
}e[N<<1];
void add(int u,int v){
    e[++tot]={u,v,ls[u]};
    ls[u]=tot;
}
namespace sch{
    int a[15],f[15],ans;
    void dfs(int u,int fa,int dp){
        f[u]=min(f[u],dp);
        for(int i=ls[u];i;i=e[i].pr){
            int v=e[i].v;
            if(v==fa)continue;
            dfs(v,u,dp+1);
        }
    }
    void tk(int u,int x){
        if(u==n+1){
            if(x!=0)return;
            for(int i=1;i<=n;i++)f[i]=INF;
            for(int i=1;i<=n;i++)
                if(a[i])dfs(i,i,0);
            int p=k;
            for(int i=1;i<n;i++)
                if(a[e[i].u] && a[e[i].v])p--;
            if(p>2)return;
            int cnt=0;
            for(int i=1;i<=n;i++)
                cnt=max(cnt,f[i]);
            ans=min(ans,cnt);
            return;
        }
        if(x){
            a[u]=1;
            tk(u+1,x-1);
            a[u]=0;
        }
        tk(u+1,x);
    }
    void solve(){
        ans=INF;
        tk(1,k);
        cout<<ans<<'\n';
    }
}
namespace k2sol{
    const int M=1e5+5;
    int cnt;
    int dfn[M],ndfn[M],rdfn[M],d[M],lg[M],st[20][M];
    int hier(int x,int y){
        return dfn[x]<dfn[y]?x:y;
    }
    int lca(int u,int v){
        if(u==v)return u;
        int x=dfn[u],y=dfn[v];
        x++;
        int l=lg[y-x+1];
        return hier(st[l][x],st[l][y-(1<<l)+1]);
    }
    int dist(int u,int v){
        return d[u]+d[v]-d[lca(u,v)];
    }
    struct node{
        int x,y,d;
        node operator+(node rhs){
            int nx=0,ny=0,nd=0,tmp=0;
            if((tmp=d)>nd)nx=x,ny=y,nd=tmp;
            if((tmp=rhs.d)>nd)nx=x,ny=rhs.y,nd=tmp;
            if((tmp=dist(rhs.x,y))>nd)nx=rhs.x,ny=y,nd=tmp;
            if((tmp=dist(rhs.x,rhs.y))>nd)nx=rhs.x,ny=rhs.y,nd=tmp;
            return {nx,ny,nd};
        }
    }t[M<<2];
    void dfs(int u,int fa){
        d[u]=d[fa]+1;
        st[0][u]=dfn[fa];
        dfn[u]=++cnt;
        ndfn[cnt]=u;
        for(int i=ls[u];i;i=e[i].pr){
            int v=e[i].v;
            if(v==fa)continue;
            dfs(v,u);
        }
        rdfn[u]=cnt;
    }
    void bld(int u,int l,int r){
        if(l==r)return t[u]={ndfn[l],ndfn[l],0},void();
        int mid=(l+r)/2;
        bld(u<<1,l,mid);bld(u<<1|1,mid+1,r);
        t[u]=t[u<<1]+t[u<<1|1];
    }
    void qry(int u,int l,int r,int L,int R,node &x){
        if(l<=L && R<=r)return x=x+t[u],void();
        int mid=(l+r)/2;
        if(L<=mid)qry(u<<1,l,mid,L,R,x);
        if(mid<R)qry(u<<1|1,mid+1,r,L,R,x);
    }
    void solve(){
        for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;
        dfs(1,0);
        for(int s=1;s<=n;s++)
            for(int i=1;i<=n-(1<<s)+1;i++)
                st[s][i]=hier(st[s-1][i],st[s-1][i+(1<<s-1)]);
        bld(1,1,n);
        for(int u=1;u<=n;u++){
            int l=dfn[u],r=rdfn[u];
            node tmp;
            for(int i=ls[u];i;i=e[i].pr){
                int v=e[i].v,nl=dfn[v],nr=rdfn[v];
                if(nl<=l && r<=nr){
                    //
                }
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;tot=0;
        for(int i=1;i<=n;i++)ls[i]=0;
        for(int i=1,u,v;i<n;i++)
            cin>>u>>v,add(u,v),add(v,u);
        //if(k==2)k2sol::solve();
        //else 
        sch::solve();
    }
}