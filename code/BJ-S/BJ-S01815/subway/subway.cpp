#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=1;i<=(n);++i)
#define lop(i,n) for(int i=(n);i;--i)
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
const int N=5e5+7,INF_LL=1e18;
int W[N],f[505][505],m,n,q,_,D;
vector<pii>G[N];
vector<pii>K[505];
int solve(){
    mem(f,0x3f);
    cin>>_>>n>>m>>D>>q;
    rep(i,n)f[i][i]=0;
    rep(i,m)cin>>W[i],G[i].reserve(D);
    rep(i,n){
        int k;cin>>k;
        while(k--){
            int a,b;cin>>a>>b;
            K[i].eb(a,b);G[a].eb(i,b);
        }
    }
    rep(i,n){
        for(pii tmp:K[i]){
            int v=tmp.X,ww=tmp.Y;
            for(pii gg:G[v]){
                int nw=gg.X,www=gg.Y;
                cmin(f[i][nw],www+ww);
            }
        }
    }
    rep(k,n)
    rep(i,n)
    if(k^i)
    rep(j,n)
    if(i!=j&&k!=j)
    cmin(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y,ans=INF_LL;
        cin>>x>>y;
        for(pii tx:G[x])
        for(pii ty:G[y])
        cmin(ans,f[tx.X][ty.X]+tx.Y+ty.Y);
        cout<<ans+W[x]+W[y]<<"\n";
    }
    return 0;
}
main(){
    FILE("subway");
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    // cerr << Time() << "\n";
    return 0;
}
