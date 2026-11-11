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

const int maxn=2.002e6;
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

int x[maxn],nxt[maxn],wr[maxn],tr[maxn],tl[maxn],su[maxn];

void solve(){
    int n,m;cin>>n>>m;
    rep(i,0,n+1,1)  x[i]=nxt[i]=wr[i]=tr[i]=tl[i]=0;
    rep(i,1,n,1)    cin>>x[i];
    x[0]=-inf,x[n+1]=inf;
    auto calc=[&](int *f){
        rep(i,1,n-1,1){
            int j=upper_bound(x+1,x+1+n,m+x[i])-x-1;
            if(j!=i && x[j]-x[i-1]>m)   nxt[i]=j;
            else                        nxt[i]=i;
        }
        rep(i,1,n,1){
            int ll=lower_bound(x+i,x+n+1,m+x[i-1]+1)-x,rr=upper_bound(x+i,x+n+1,m+x[i])-x-1;
            wr[i]=rr-ll+1;
        }
        int ans=0;
        rep(i,1,n,1)    su[i]=wr[i];
        per(i,n,1,1)    if(i!=nxt[i]){
            su[i]+=su[nxt[i]];
        }
        rep(i,2,n,1){
            f[i]=0;
            int ll=lower_bound(x+i,x+n+1,m+x[i-2]+1)-x,rr=upper_bound(x+i,x+n+1,m+x[i-1])-x-1;
            f[i]=rr-ll+1;
            int j=upper_bound(x+1,x+1+n,m+x[i])-x-1;
            if(x[j]-x[i-1]<=m && x[j]-x[i-2]>m)    f[i]+=su[j];
        }
    };
    int ans=0;
    rep(i,2,n,1){
        if(x[i]-x[i-1]<=m && x[i]-x[i-2]>m && x[i+1]-x[i-1]>m)  ans--; 
    }
    calc(tr);
    rep(i,1,n,1)    x[i]=-x[i];
    reverse(x+1,x+1+n);

    calc(tl);
    reverse(tl+1,tl+1+n);
    rep(i,2,n,1)    ans+=tl[i-1]*tr[i];
    cout<<ans<<'\n';
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--)  solve();
    return 0;
}