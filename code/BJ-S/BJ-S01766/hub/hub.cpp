#include<bits/stdc++.h>
using namespace std;
namespace Mortis{
constexpr int maxn=1000001;
int n,k;
int par[maxn];
vector<int>edge[maxn];
namespace init{
vector<int>e[maxn];
int que[maxn],fr,tl;
int work(){
    cin>>n>>k;
    for(int _=n-1,u,v;_--;)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    par[1]=0;
    for(fr=0,tl=1,que[0]=1;fr<tl;++fr){
        int u=que[fr];
        for(const auto&v:e[u])
            if(v!=par[u])
                par[v]=u,que[tl++]=v;
    }
    int L=que[n-1];
    par[L]=0;
    for(fr=0,tl=1,que[0]=L;fr<tl;++fr){
        int u=que[fr];
        for(const auto&v:e[u])
            if(v!=par[u])
                par[v]=u,que[tl++]=v;
    }
    int R=que[n-1],d=0;
    for(int cur=R;cur!=L;cur=par[cur])++d;
    int I=que[n-1];
    for(int _=d/2;_--;I=par[I]);
    par[1]=0,que[0]=0;
    for(fr=1,tl=2,que[1]=I;fr<tl;++fr){
        int u=que[fr];edge[fr].clear();
        for(const auto&v:e[u])
            if(v!=que[par[fr]])
                par[tl]=fr,edge[fr].push_back(tl),que[tl++]=v;
    }fill(e+1,e+n+1,vector<int>{});
    return d/2;
}
}
int ht[maxn],son[maxn];
int f[maxn],g[maxn];
int Cht[maxn];
vector<int>F[maxn],G[maxn];
int que[maxn],fr,tl;
int dp[maxn];
int gg[maxn*2];
int R;
bool dfs(int u,int dep){
    int bkfr=fr,bktl=tl;
    vector<int>bk;
    for(;fr<tl&&gg[que[tl-1]]>g[u];bk.push_back(que[--tl]));
    gg[dep-1]=g[u],que[tl++]=dep-1;
    if(dp[u]+gg[que[fr]]<=k)return true;
    if(ht[u]==R)return false;
    if(son[u]){
        int l=0;
        for(const auto&v:edge[u])if(v!=son[u])l=max(l,ht[v]+1);
        for(;fr<tl&&dep-que[fr]+l>R;++fr);
        dfs(son[u],dep+1);
        for(;fr<tl&&dep-que[fr]+ht[u]>R;++fr);
        for(const auto&v:edge[u])if(v!=son[u]&&ht[v]>=R&&dfs(v,dep+1))return true;
        fr=bkfr;
    }
    tl=bktl;
    for(int i=0;i<bk.size();++i)que[tl-1-i]=bk[i];
    return false;
}
bool check(){
    fill(f+1,f+n+1,1);
    for(int i=n;i>1;--i)
        if(ht[i]>=R)
            f[par[i]]+=f[i];
    g[1]=n+1;
    for(int i=1;i<=n;++i){
        if(!son[i])continue;
        int s=f[i];
        if(Cht[i]>R)s+=g[i];
        for(const auto&j:edge[i])
            g[j]=s-(ht[j]>=R?f[j]:0);
    }
    for(int i=1;i<=n;++i)if((f[i]<=k&&Cht[i]<=R)||(g[i]<=k&&ht[i]<R))return true;
    son[1]=0;
    for(int p=n;p>=2;--p){
        if(son[par[p]]==p)continue;
        vector<int>a(ht[p]+1);
        for(int i=0,u=p;i<=ht[p];++i,u=son[u])a[i]=u;
        auto&b=F[p];b=vector<int>(ht[p]+1,n+1);
        fr=tl=0;
        auto push=[&b](int i){
            for(;fr<tl&&b[que[tl-1]]>b[i];--tl);
            que[tl++]=i;
        };
        for(int i=ht[p];i>=0;--i){
            int u=a[i],l=0;
            for(const auto&v:edge[u])
                if(v!=son[u])
                    l=max(l,ht[v]+1);
            for(int j=max(0,i+R+1-ht[p]);j<=min(R,l);++j)b[i+R+1-j]=n+1;
            for(const auto&v:edge[u])
                if(v!=son[u])
                    for(int j=0;j+1+ht[u]<=R&&j<=ht[v];++j)b[i+1+j]=max(b[i+1+j],F[v][j]);
            for(;fr<tl&&que[fr]-i+l>R;++fr);
            for(;fr<tl&&que[tl-1]<=i+l;--tl);
            b[i]=f[u];
            for(int j=i+l;j>=i;--j)push(j);
            dp[u]=b[que[fr]];
        }
    }
    int cnt=0;
    for(const auto&v:edge[1])if(ht[v]>=R)++cnt;
    if(cnt==1){
        fr=tl=0;
        if(dfs(son[1],0))return true;
    }else if(cnt==2){
        fr=tl=0;
        int x=son[1],y=-1;
        for(const auto&v:edge[1])if(ht[v]>=R&&v!=x)y=v;
        for(int j=ht[y];j>=0;--j)
            if(F[y][j]<=k){
                gg[ht[y]-j]=F[y][j];
                for(;fr<tl&&gg[que[tl-1]]>F[y][j];--tl);
                que[tl++]=ht[y]-j;
            }
        if(dfs(x,ht[y]+2))return true;
        for(int j=ht[x];j>=0;--j)
            if(F[x][j]<=k){
                gg[ht[x]-j]=F[x][j];
                for(;fr<tl&&gg[que[tl-1]]>F[x][j];--tl);
                que[tl++]=ht[x]-j;
            }
        if(dfs(y,ht[x]+2))return true;
    }else{
        for(const auto&v:edge[1])if(ht[v]>=R&&(fr=tl=0,dfs(v,1)))return true;
    }return false;
}
void work(){
    init::work();
    if(k==n){cout<<"0\n";return;}
    fill(ht+1,ht+n+1,0),fill(son+1,son+n+1,0);
    for(int i=n;i>1;--i)if(ht[i]+1>ht[par[i]])ht[par[i]]=ht[i]+1,son[par[i]]=i;
    for(int i=1;i<=n;++i){
        if(!son[i])continue;
        if(Cht[i]>=ht[i])for(const auto&j:edge[i])Cht[j]=Cht[i]+1;
        else{
            int h=Cht[i];
            for(const auto&j:edge[i])if(j!=son[i])h=max(h,ht[j]+1),Cht[j]=ht[i]+1;
            Cht[son[i]]=h+1;
        }
    }
    int l=1,r=min(n-k,ht[1]);
    for(;l<r;){
        R=l+r>>1;
        if(check())r=R;
        else l=R+1;
    }cout<<l<<'\n';
}
void main(){
    int c,t;
    for(cin>>c>>t;t--;work());
}
}
int main(){
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    Mortis::main();
    return 0;
}