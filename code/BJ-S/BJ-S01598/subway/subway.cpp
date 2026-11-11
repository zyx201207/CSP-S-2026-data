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

const int maxn=5.2e5;
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

vpii vec[maxn];
vpii a[maxn];
int ww[maxn];
int dis[520][520];

signed main(){
     freopen("subway.in","r",stdin);
     freopen("subway.out","w",stdout);
    int _,n,m,d,q;cin>>_>>n>>m>>d>>q;
    rep(i,1,m,1)    cin>>ww[i];
    rep(i,1,n,1){
        int k;cin>>k;a[i].resize(k+1);
        rep(j,1,k,1)    cin>>a[i][j]._1>>a[i][j]._2,vec[a[i][j]._1].pb({i,j});
    }
    memset(dis,0x3f,sizeof(dis));
    rep(i,1,n,1)    dis[i][i]=0;
    rep(u,1,m,1)    for(auto [i1,j1]:vec[u])    for(auto [i2,j2]:vec[u])    if(i1<i2){
        chkmin(dis[i1][i2],a[i1][j1]._2+a[i2][j2]._2);
        chkmin(dis[i2][i1],a[i1][j1]._2+a[i2][j2]._2);
    }
    rep(k,1,n,1)    rep(i,1,n,1)    rep(j,1,n,1)    chkmin(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int u,v;cin>>u>>v;
        int ans=inf;
        for(auto [i1,j1]:vec[u])    for(auto [i2,j2]:vec[v])    chkmin(ans,dis[i1][i2]+a[i1][j1]._2+a[i2][j2]._2);
        cout<<ans+ww[u]+ww[v]<<'\n';
    }
    return 0;
}