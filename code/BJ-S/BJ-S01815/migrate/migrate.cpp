#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=1;i<=(n);++i)
#define lop(i,n) for(int i=(n);i;--i)
#define hh(i,a,b) for(int i=a;i<=b;++i)
#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define pii pair<int,int>
#define X first
#define Y second
#define prq priority_queue
#define eb emplace_back
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
double Time(){
    return 1.*clock()/CLOCKS_PER_SEC;
}
void cmax(int&a,int b){
    if(a<b)a=b;
}
void cmin(int&a,int b){
    if(a>b)a=b;
}
const int N=2e6+7,INF_LL=1e18;
int nn,n,f[N],g[N],xx[N],x[N],d,nxt[N];
int b[N];
int calc(){
    rep(i,n)f[i]=g[i]=0;
    int j=1,ans=0;
    rep(i,n){
        while(j<=n&&x[j]-x[i]<=d)++j;
        --j;nxt[i]=j;
    }
    f[n]=0;
    lop(i,n-1){
        int t=nxt[i];
        if(t==i+1){
            f[i]=f[t]+t-i;continue;
        }
        if(nxt[t-1]==nxt[t]){
            f[i]=t-i;
            continue;
        }
        f[i]=f[t]+t-i-(nxt[t-1]-t);
    }
    g[n]=0;b[n]=-1;
    if(nxt[n-1]+1<nxt[n])b[n]=n;
    lop(i,n-1){
        int t=nxt[i];
        b[i]=b[t];
        // cerr<<t<<"\n";
        if(i!=1&&nxt[i-1]+1<nxt[i])
        b[i]=i;
        if(nxt[i-1]==nxt[i])b[i]=-1;
        if(i+1==t){
            g[i]=g[t]+1;
            continue;
        }
        if(nxt[t]==nxt[t-1]){
            if(nxt[t-2]==nxt[t]){
                g[i]=t-i;
                continue;
            }
            // if(i==1)cerr<<t<<"\n";
            g[i]=f[t]+t-i;
            if(nxt[t-2]>=t)
            g[i]-=nxt[t-2]-t;
            continue;
        }//cerr<<"? "<<i<<"\n";
        int tt=b[t];
        // if(i==1)
        // cerr<<"? "<<t<<"\n";
        g[i]=f[t];
        if(tt!=-1)
        g[i]+=g[tt]-f[tt];
        if(nxt[t-2]>=t)
        g[i]-=nxt[t-2]-t;
        g[i]+=t-i;
    }
    rep(i,n)ans+=g[i]-f[i];
    // rep(i,n)cout<<f[i]<<" ";cout<<"\n";
    // rep(i,n)cout<<g[i]<<" ";cout<<"\n";
    return ans;
}
int solve(){
    int ans=0;
    cin>>nn>>d;n=0;
    rep(i,nn){
        cin>>xx[i];
        if(i!=1&&xx[i]-xx[i-1]>d){
            ans+=calc();
            n=1;x[1]=xx[i];
        }else{
            x[++n]=xx[i];
        }
    }
    ans+=calc();
    cout<<ans<<"\n";
    return 0;
}
main(){
    FILE("migrate");
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _,T=1;
    cin>>_>>T;
    while(T--)solve();
    // cerr << Time() << "\n";
    return 0;
}