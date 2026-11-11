#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b,c)    for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c)    for(int i=(a);i>=(b);i-=(c))
#define pb push_back
#define vint vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
#define _1 first 
#define _2 second

using namespace std;

const int maxn=1.002e6;
const int inf=(sizeof(int)==4?0x3f3f3f3f:0x3f3f3f3f3f3f3f3f);

template<typename T> void chkmax(T &x,const T&y){
    x=(x>y?x:y);
}
template<typename T> void chkmin(T &x,const T&y){
    x=(x<y?x:y);
}

struct BIT{
    int num[maxn],n;
    inline int lb(int x){   return x&(-x);}
    void padd(int p,int v){
        p++;while(p<=n){    num[p]+=v;p+=lb(p);}
    }
    int qsum(int p){
        p++;int ans=0;
        while(p){   ans+=num[p];p-=lb(p);}
        return ans;
    }
};

// 16:33 solve D

vint adj[maxn];
int d[maxn],hs[maxn],h[maxn],pool[maxn*10],*it,k;
int *g[maxn],sz[maxn],gg[maxn];
int out[maxn];

void init(int u,int fa){
    for(auto v:adj[u])   if(v!=fa){
        d[v]=d[u]+1;
        init(v,u);
        if(h[u]<h[v]+1){
            h[u]=h[v]+1;hs[u]=v;
        }
    }
}
void dfs(int u,int fa){
    pii o[3]={{-inf,0},{-inf,0}};
    for(auto v:adj[u])  if(v!=fa){    o[2]={h[v]+1,v};sort(o,o+3,greater<pii>());}
    for(auto v:adj[u])  if(v!=fa){
        out[v]=out[u]+1;
        chkmax(out[v],(o[0]._2==v?o[1]._1+2:o[0]._1+2));
        dfs(v,u);
    }
}
int ans=inf;
void dp0(int u,int fa){
    if(hs[u]){
        g[hs[u]]=g[u]+1;//gg[hs[u]]=gg[u]+1;
        // cerr<<"O.o"<<endl;
        dp0(hs[u],u);
        sz[u]=sz[hs[u]]+1;
    }
    for(auto v:adj[u])  if(v!=fa && v!=hs[u]){
        g[v]=it;it+=h[v]+2;
        // gg[v]=it2;it2+=h[v]+1;
        dp0(v,u);
    }
    pii o[4]={{-inf,0},{-inf,0},{-inf,0}};
    for(auto v:adj[u])  if(v!=fa){    o[3]={h[v],v};sort(o,o+4,greater<pii>());}
    if(out[u]<k && adj[u].size()-(fa!=0)>=2){
        // for(auto v1:adj[u]) if(v1!=fa)   for(auto v2:adj[u]) if(v2!=fa && sz[v1]<=sz[v2]){
        //     int t0=out[u]+1;
        //     if(v1==o[0]._2 || v2==o[0]._2){
        //         if(v1==o[1]._2 || v2==o[1]._2)    chkmax(t0,o[2]._1+2);
        //         else    chkmax(t0,o[1]._1+2);
        //     }else   chkmax(t0,o[0]._1+2);
        //     t0=k-t0;
        //     rep(i,0,min(sz[v1],t0),1)   chkmin(ans,g[v1][i]+g[v2][min(t0,k-2-i)]);
        // }
        // for(auto v:adj[u])  if(v!=fa && v!=hs[u]){
        //     int t0=out[u]+1;
        //     if(hs[u]==o[0]._2 || v==o[0]._2){
        //         if(hs[u]==o[1]._2 || v==o[1]._2)    chkmax(t0,o[2]._1+2);
        //         else    chkmax(t0,o[1]._1+2);
        //     }
        //     rep(i,0,k-max(out[u]+1),1){

        //     }
        // }
        int t0=k-max(out[u]+1,o[0]._1+2);chkmin(t0,k);
        int ww[3]={inf,inf,inf};
        if(t0>=0){
            for(auto v:adj[u])  if(v!=fa)   ww[2]=g[v][min(t0,sz[v])],sort(ww,ww+3);
            chkmin(ans,ww[0]+ww[1]);
            // if(ww[0]+ww[1]==42){
                // cerr<<"!!"<<u<<endl;
            // }
        }
        t0=k-max(out[u]+1,o[1]._1+2);chkmin(t0,k);
        if(t0>=0){
            ww[0]=inf;
            for(auto v:adj[u])  if(v!=fa && v!=o[0]._2)   chkmin(ww[0],g[v][min(t0,sz[v])]);
            chkmin(ans,ww[0]+g[o[0]._2][min(t0,sz[o[0]._2])]);  
            // if(ww[0]+g[o[0]._2][t0]==42){
                // cerr<<"!!"<<u<<" "<<ww[0]<<" "<<g[o[0]._2][t0]<<" "<<t0<<endl;
            // }  
        }
        t0=k-max(out[u]+1,o[2]._1+2);chkmin(t0,k);
        if(t0>=0){
            chkmin(ans,g[o[0]._2][min(t0,sz[o[0]._2])]+g[o[1]._2][min(t0,sz[o[1]._2])]);
            // if(g[o[0]._2][t0]+g[o[1]._2][t0]==42){
                // cerr<<"!!"<<u<<" "<<ww[0]<<" "<<g[o[0]._2][t0]<<" "<<g[o[1]._2][t0]<<" "<<t0<<" "<<o[0]._2<<" "<<o[1]._2<<" "<<o[2]._1<<" "<<adj[u].size()<<" "<<out[u]<<endl;
            // }  
        }
    }

    // ran u
    int ss=1;
    for(auto v:adj[u])  if(v!=fa && h[v]>=k)    ss+=g[v][0];
    gg[u]=inf;
    for(auto v:adj[u])  if(v!=fa){
        int cur=g[v][sz[v]];
        // cerr<<"??"<<v<<" "<<sz[v]<<" "<<k<<en
               // zhen de yao cong 0 ma
        chkmin(gg[u],min(gg[v],cur)+ss-(h[v]>=k?g[v][0]:0));
        // if(u==135 && )
        // if(u==135 && min(gg[v],cur)+ss-(h[v]>=k?g[v][0]:0)==1){
            // cerr<<sz[v]<<" "<<k<<endl;
            // cerr<<"??"<<v<<" "<<gg[v]<<" "<<cur<<" "<<ss-1-(h[v]>=k?g[v][0]:0)<<endl;
        // }
    }
    g[u][0]=ss;
    // if(u==2){
        // cerr<<g[3][1]<<" "<<gg[2]<<" "<<out[u]<<endl;
    // }
    chkmin(gg[u],g[u][0]);
    if(out[u]<=k){
        chkmin(ans,gg[u]);
        // if(gg[u]==42){
            // cerr<<"????"<<u<<" "<<d[u]<<" "<<out[u]<<" "<<g[u][0]<<" "<<ss<<endl;
        // }
    }
    chkmin(sz[u],k-(o[0]._2!=hs[u]?o[0]._1+1:o[1]._1+1));
    chkmax(sz[u],0ll);
    for(auto v:adj[u])  if(v!=fa && v!=hs[u]){
        int oo=min(sz[v],k-(o[0]._2!=v?o[0]._1+2:o[1]._1+2));
        if(oo<0)    continue ;
        if(sz[u]<oo+1){
            rep(i,sz[u]+1,oo+1,1) g[u][i]=inf;
            sz[u]=oo+1;
        }
        rep(i,0,oo,1)   chkmin(g[u][i+1],g[v][i]);
        if(oo>=0 && oo+1<sz[u] && g[u][oo+2]<g[u][oo+1]){
            // cerr<<"??"<<endl;
            rep(i,oo+2,sz[u],1) g[u][i]=g[u][oo+1];
        }
    }
    chkmin(sz[u],k);
}

void solve(){
    int n,li;cin>>n>>li;
    rep(i,0,n,1)    adj[i].clear(),d[i]=hs[i]=h[i]=sz[i]=gg[i]=out[i]=0,g[i]=0;
    rep(i,0,5*n,1)  pool[i]=0;
    rep(i,2,n,1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);adj[v].pb(u);
    }
    int anss=(n+1)/2+1;
    rep(rt,1,(n<=2000?n:(n<=4009?n/2:(n<=1e5?80:5))),1){
        rep(i,1,n,1)    d[i]=hs[i]=h[i]=sz[i]=gg[i]=out[i]=0;
        rep(i,0,5*n,1)  pool[i]=0;
        init(rt,0);dfs(rt,0);
        auto chk=[&](int k)->bool{
            // Single : long lk pou
            rep(i,0,n,1)    sz[i]=gg[i]=0,g[i]=0;
            rep(i,0,5*n,1)  pool[i]=0;
            ::k=k;ans=inf;
            it=pool+4;g[rt]=(pool)+4;it+=h[rt]+1;
            // cerr<<g[1][0]<<endl;
            dp0(rt,0);
            // cerr<<k<<":"<<ans<<" "<<li<<endl;
            return (ans<=li);
            // gg[0]=(pool2)+4;it2+=h[1]+1;
        };
        if(li==n){    cout<<"0\n";return ;}
        // chk(6);
        // if(chk(6)){
        //     cerr<<"!!"<<rt<<endl;
        // }
        int tl=1,tr=anss-2,ans=anss-1;
        if(!chk(anss-1))    continue ;
        while(tl<=tr){
            int mid=(tl+tr)>>1;
            if(chk(mid))    ans=mid,tr=mid-1;
            else            tl=mid+1;
        }
        // cout<<ans<<'\n';
        chkmin(anss,ans);
    }
    cout<<anss<<'\n';
    // cerr<<n<<" "<<li<<endl;
    // exit(0);
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--)  solve();
    return 0;
}