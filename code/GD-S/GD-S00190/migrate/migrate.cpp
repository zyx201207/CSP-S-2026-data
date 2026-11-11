#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define eb emplace_back
using namespace std;

inline ll read(){
    char c=getchar();ll f=1,x=0;
    for(;c<'0'||c>'9';c=getchar())if(c=='-') f=-1;
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}

const int N=1e6+10,M=N*4,mod=998244353;
int c,n,fa[N],cnt[N],nx[N],h[N],rt;ll d,a[N],ans;
vector<int> g[N];
void slv(int l,int r){
    // rep(i,l,r){
    //     if(cnt[fa[i]]) nx[i]=i,h[i]=cnt[fa[i]];
    //     cnt[fa[i]]++;
    // }
    // per(i,r,l)if(!nx[i]) nx[i]=nx[fa[i]];
    // per(i,r-1,l){
    //     int L=nx[fa[i]],R=nx[fa[L]];
    //     if(h[L]>2) continue;
    //     if(h[L]==2) R=fa[L];
    //     int lst=i;
    //     // if(i==1) cerr<<L<<' '<<R<<'\n';
    //     for(int a=fa[i],b=fa[a];a!=r;lst=a,a=b,b=fa[b]){
    //         if(b>R) break;
    //         rep(x,a+1,b-1){
    //             int num=0;
    //             rep(y,lst+1,a-1){
    //                 if(x<=fa[y]) num++;
    //                 if(num>=2) break;
    //             }
    //             if(num==1-(b>L)) ans++;
    //         }
    //         if(b>L) ans++;
    //     }
    // }
}
struct T{
    int v,c;
    T(int x=0,int y=0){v=x,c=y;}
    inline friend T operator+(T a,T b){
        if(a.v==b.v) return T(a.v,a.c+b.c);
        return a.v<b.v?a:b;
    };
};
struct SGT{
    #define ls (x<<1)
    #define rs (x<<1|1)
    int L[M],R[M],t[M];T v[M];
    void pu(int x){v[x]=v[ls]+v[rs],v[x].v+=t[x];}
    void cal(int x,int k){t[x]+=k,v[x].v+=k;}
    void upd(int l,int r,int k,int x=1){
        if(L[x]>r||R[x]<l) return;
        if(l<=L[x]&&R[x]<=r) return cal(x,k);
        upd(l,r,k,ls);upd(l,r,k,rs);pu(x);
    }
    T qry(int l,int r,int x=1){
        if(L[x]>r||R[x]<l) return T(1e9,0);
        if(l<=L[x]&&R[x]<=r) return v[x];
        T h=qry(l,r,ls)+qry(l,r,rs);
        h.v+=t[x];return h;
    }
    void bd(int l=1,int r=n,int x=1){
        L[x]=l,R[x]=r,t[x]=0,v[x]=T(0,r-l+1);
        if(l==r) return;
        int m=l+r>>1;
        bd(l,m,ls);bd(m+1,r,rs);
    }
}t;
struct H{int l,r,k;}s[N*8];int top;
int cc=0;
void U(int l,int r,int k){
    cc++;
    s[++top]={l,r,k};
    t.upd(l,r,k);
}
void back(int h){
    while(top>h){
        auto [l,r,k]=s[top--];
        t.upd(l,r,-k);
    }
}
void work(int u,int l,int r){
    if(l>r) return;
    rep(i,l,r) cnt[i]++;
    per(i,r,max(l,r-1)){
        if(cnt[i]>=4) return;
        int f=fa[u];
        work(f,f+1,fa[i]);
    }
}
void dfs(int u){
    vector<int> C(n+2);
    rep(i,1,n) C[i]=cnt[i];
    int lst=u,nw=top;
    for(int v:g[u]){
        if(v<u-2&&lst!=u){
            rep(i,v,lst-1) cnt[i]++;
            // U(v,lst-1,1);
        }
        else{
            rep(i,1,n) cnt[i]=C[i];
            cnt[v]=1;
            // back(nw);U(v,v,1);
            work(v,v+1,u-1);
        }
        rep(i,u+1,rt) ans+=cnt[i]==2;
        // rep(i,u+1,rt){
        //     auto [x,y]=t.qry(i,i);
        //     ans+=x==2;
        // }
        dfs(v);
        lst=v;
    }
    rep(i,1,n) cnt[i]=C[i];
    // back(nw);
}
void Apeiria(){
    cc=0;
    rep(i,0,n+1) fa[i]=nx[i]=a[i]=cnt[i]=h[i]=0,g[i].clear();ans=0;
    n=read(),d=read();
    rep(i,1,n) a[i]=read();
    fa[n]=n;
    per(i,n-1,1){
        fa[i]=fa[i+1];
        while(a[fa[i]]-a[i]>d) fa[i]--;
    }
    per(i,n,1)if(fa[i]^i) g[fa[i]].eb(i);
    t.bd();
    rep(i,1,n)if(i==fa[i]){
        rt=i;
        cnt[i]=1;
        dfs(i);
        cnt[i]=0;
        // U(i,i,1);
        // dfs(i);
        // back(0);
    }
    printf("%lld\n",ans);
    // cerr<<n<<' '<<cc<<'\n';
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();int T=read();
    rep(i,1,T) Apeiria();
    return 0;
}
