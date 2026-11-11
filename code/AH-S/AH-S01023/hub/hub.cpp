#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int n,k; vector<int> v[N];
bool ok[N];
int mx,p,fx[N],m,id[N];

void dfs(int x,int ow,int fa) {
    fx[x]=fa;
    if(ow>=mx) mx=ow,p=x;
    for(auto u:v[x]) if(u!=fa) dfs(u,ow+1,x);
}

int h[N],kk[N],tp,sum[N];

void dfs2(int x,int ow,int fa) {
    h[x]=ow; kk[tp]=max(kk[tp],ow);
    for(auto u:v[x]) if(u!=fa && !ok[u]) dfs2(u,ow+1,x);
}

int ri[N],g[N];

bool chk(int d) {
    for(int i=1;i<=n;++i) ri[i]=m+1;
    int ww=sum[d+1];
    for(int i=1,x;i<=m;++i) {
        x=id[i];
        if(kk[x]>d) ri[i]=i;
        else {
            int lp=i-(d-kk[x]),rp=i+(d-kk[x]);
            lp=max(lp,1),rp=min(rp,m);
            ri[lp]=min(ri[lp],rp);
        }
    } 
    int mn=1e9;
    for(int i=1;i<=m;++i) g[i]=0;
    for(int i=1,mxl=0,mnr=1e9;i<=m;++i) {
        if(ri[i]!=m+1) mxl=i,mnr=min(mnr,ri[i]);
        if(mxl) g[i]+=max(1,mxl-mnr+1);
    }
    for(int i=m,mxl=0,mnr=1e9;i>=1;--i) {
        if(ri[i]!=m+1) mxl=max(mxl,i),mnr=min(mnr,ri[i]);
        if(mxl) g[i-1]+=max(1,mxl-mnr+1);
    }
    for(int i=1;i<=m;++i) mn=min(mn,g[i]);
    return mn+ww<=k;
}

namespace bf {
    int D,sum;
    bool tag;

    int dfs(int x,int fa,int ok) { 
        if(!x) return 0;
        int o=0;
        for(auto u:v[x]) if(u!=fa) o=max(o,dfs(u,x,0)+1);
        sum+=(ok||o>=D);
        return o;
    }

    int dp[N],ow[N],sz[N],sz2[N];

    void dfs2(int x,int fa) {
        if(!x) return ; sz[x]=1;
        if(dp[x]>D) sz2[x]=1; else sz2[x]=0;
        for(auto u:v[x]) if(u!=fa) {
            dp[u]=dp[x]+1; dfs2(u,x);
            sz[x]+=sz[u]; sz2[x]+=sz2[u];
        } 
    }

    int dfs4(int x,int fa,int ok) { 
        if(!x) return 0;
        int o=0;
        for(auto u:v[x]) if(u!=fa) o=max(o,dfs4(u,x,0)+1);
        sum-=(ok||o<D);
        return o;
    }

    void dfs3(int x,int fa) {
        if(!x) return ;
        for(auto u:v[x]) if(u!=fa) {
            if(sz2[u]==sz2[x]) { dfs3(u,x); return ; }
        }
        sum+=sz[x];
        int tmp=dfs4(x,fa,0);
    }

    bool chk(int d) {
        D=d;
        for(int i=1;i<=n;++i) {
            sum=0;
            int tmp=dfs(i,fx[i],1);
            dp[fx[i]]=1;
            dfs2(fx[i],i); dfs3(fx[i],i);
            if(sum<=k) return true;
        }
        return false;
    }

    void solve() {
        int l=1,r=n,mid,ans=-1;
        for(;l<=r;) {
            mid=(l+r)>>1;
            if(chk(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
};

void wk() { 
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) v[i].clear();
    for(int i=1,x,y;i<n;++i) {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(k==n) { printf("0\n"); return ; }
    for(int i=1;i<=n;++i) ok[i]=false;
    mx=-1; dfs(1,0,0);
    mx=-1; int rt=p; dfs(p,0,0);
    if(n<=1000 && k!=2) { bf::solve(); return ; }
    m=0; // cerr << rt << ' ' << p << "\n";
    for(int x=p;;x=fx[x]) {
        ok[x]=true; id[++m]=x;
        if(x==rt) break;
    }
    for(int i=1;i<=n;++i) h[i]=kk[i]=0;
    for(int i=1;i<=n;++i) if(ok[i]) {
        tp=i; dfs2(i,0,0);
    }
    for(int i=1;i<=n;++i) sum[i]=0;
    for(int i=1;i<=n;++i) ++sum[h[i]];
    for(int i=n-1;i>=1;--i) sum[i]+=sum[i+1];
    int l=1,r=m,mid,ans=-1;
    for(;l<=r;) {
        mid=(l+r)>>1;
        if(chk(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
}

signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t; scanf("%d%d",&c,&t);

    for(;t--;) wk();

    return 0;
}