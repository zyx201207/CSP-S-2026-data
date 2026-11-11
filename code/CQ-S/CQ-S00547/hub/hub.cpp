#include<bits/stdc++.h>
using namespace std;
namespace mycode{
    int n,Kx;
    int fth[1000005];
    vector<int> b[1000005];
    int dep[1000005];
    int bz[1000005][20];
    void dfsp(int u,int fa){
        fth[u]=fa;dep[u]=dep[fa]+1;
        bz[u][0]=fa;for(int i=1;i<=19;i++) bz[u][i]=bz[bz[u][i-1]][i-1];
        for(auto v:b[u]) if(v!=fa) dfsp(v,u);
    }
    inline int getup(int u,int k){for(int i=19;i>=0;i--){if((k>>i)&1) u=bz[u][i];}return u;}
    inline int lca(int u,int v){
        if(dep[u]<dep[v]) swap(u,v);
        u=getup(u,dep[u]-dep[v]);
        if(u==v) return u;
        for(int i=19;i>=0;i--) if(bz[u][i]!=bz[v][i]){
            u=bz[u][i];
            v=bz[v][i];
        }
        return bz[u][0];
    }
    inline int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
    inline int mv(int u,int v,int k){
        int t=lca(u,v);
        if(k<=dep[u]-dep[t]) return getup(u,k);
        return getup(v,(dep[u]+dep[v]-2*dep[t])-k);
    }
    int k;
    bool flg;
    int fd[1000005],gd[1000005];
    int fs[1000005],gs[1000005];
    int frt[1000005],grt[1000005];
    int fas[1000005],gas[1000005];
    void dfs1(int u,int fa){
        for(auto v:b[u]) if(v!=fa){
            dfs1(v,u);
            fd[u]=max(fd[u],fd[v]+1);
            fs[u]+=fs[v];
        }
        if(fd[u]>=k) fs[u]++;
        int kcnt=0,kw=0;
        for(auto v:b[u]) if(v!=fa)
            if(fd[v]+1>k){kcnt++;kw=v;}
        if(kcnt==0){fas[u]=1;frt[u]=u;}
        else if(kcnt>=2){fas[u]=fs[u];frt[u]=u;}
        else{
            int kmx=0;
            for(auto v:b[u]) if(v!=fa && v!=kw) kmx=max(kmx,fd[v]+1);
            int l=dep[frt[kw]]-dep[u];
            if(kmx+l<=k){
                fas[u]=fas[kw];
                frt[u]=frt[kw];
            }
            else{
                fas[u]=fas[kw]+(kmx+l-k);
                frt[u]=mv(frt[kw],u,kmx+l-k);
            }
        }
        // printf("f %d:%d %d %d\n",u,fd[u],fs[u],fas[u]);
    }
    void dfs2(int u,int fa){
        int kcnt=0,kw1=0,kw2=0;
        int ssum=0;
        int df=0,ds=0;
        if(fa){
            if(gd[u]+1>k){
                kcnt++;
                if(kw1) kw2=fa;
                else kw1=fa;
            }
            ssum+=gs[u];
            int t=gd[u]+1;
            if(t>df){ds=df;df=t;}
            else if(t>ds) ds=t;
        }
        for(auto v:b[u]) if(v!=fa){
            if(fd[v]+1>k){
                kcnt++;
                if(kw1) kw2=v;
                else kw1=v;
            }
            ssum+=fs[v];
            int t=fd[v]+1;
            if(t>df){ds=df;df=t;}
            else if(t>ds) ds=t;
        }
        for(auto v:b[u]) if(v!=fa){
            int t=fd[v]+1;
            gd[v]=((t==df)?ds:df);
            gs[v]=ssum-fs[v]+(gd[v]>=k);
        }
        for(auto v:b[u]) if(v!=fa){
            if(fd[v]+1>k) kcnt--;
            if(kcnt==0){gas[v]=1;grt[v]=u;}
            else if(kcnt>=2){gas[v]=gs[v];grt[v]=u;}
            else{
                int kw=((v==kw1)?kw2:kw1);                
                gas[v]=gs[v];
                int kmx=0;
                for(auto tv:b[u]) if(tv!=v && tv!=kw) kmx=max(kmx,((tv==fa)?gd[u]:fd[tv])+1);
                if(kw==fa){
                    int l=dis(u,grt[u]);
                    if(kmx+l<=k){
                        gas[v]=gas[u];
                        grt[v]=grt[u];
                    }
                    else{
                        gas[v]=gas[u]+(kmx+l-k);
                        grt[v]=mv(grt[u],u,kmx+l-k);
                    }
                }
                else{
                    int l=dep[frt[kw]]-dep[u];
                    if(kmx+l<=k){
                        gas[v]=fas[kw];
                        grt[v]=frt[kw];
                    }
                    else{
                        gas[v]=fas[kw]+(kmx+l-k);
                        grt[v]=mv(frt[kw],u,kmx+l-k);
                    }
                }
            }
            if(gas[v]+fas[v]<=Kx){flg=true;return;}
            if(fd[v]+1>k) kcnt++;
        }
        for(auto v:b[u]) if(v!=fa){
            dfs2(v,u);
            if(flg) return;
        }
    }
    bool check(int _x){
        k=_x;flg=false;
        dfs1(1,0);
        if(fas[1]<=Kx) flg=true;
        if(!flg) dfs2(1,0);
        for(int i=1;i<=n;i++){
            fd[i]=gd[i]=0;
            fs[i]=gs[i]=0;
            frt[i]=grt[i]=0;
            fas[i]=gas[i]=0;
        }
        return flg;
    }
    void solve(){
        cin>>n>>Kx;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            b[u].push_back(v);
            b[v].push_back(u);
        }
        dfsp(1,0);
        // printf("%d\n",check(0));
        // return;
        int l=0,r=n,m;
        while(l<r){
            m=(l+r)>>1;
            if(check(m)) r=m;
            else l=m+1;
        }
        printf("%d\n",l);
    }
    void clear(){
        for(int i=1;i<=n;i++){
            fth[i]=0;
            dep[i]=0;
            for(int j=0;j<=19;j++) bz[i][j]=0;
            b[i].clear();
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;cin>>c>>t;
    while(t--){mycode::solve();mycode::clear();}
    return 0;
}