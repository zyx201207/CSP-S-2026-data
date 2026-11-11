#include<bits/stdc++.h>
bool Mbe;
#define il inline
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
template<typename tt> il bool cmax(tt&x, const tt&y) {return x<y?x=y,1:0; }
template<typename tt> il bool cmin(tt&x, const tt&y) {return y<x?x=y,1:0; }
#define sz(x) ((int)x.size())
#define pub push_back
const int H=500, W=5e5+500;
namespace G {
    int hd[W+3], nxt[W+3]; pii to[W+3]; int pt=0;
    il void edge(int u, int v, int l) {
        ++pt, to[pt]={v,l}, nxt[pt]=hd[u], hd[u]=pt; 
    }
} 
namespace flo {
    ll dis[H+3][H+3];
    il void edge(int u, int v, ll l) { cmin(dis[u][v],l), cmin(dis[v][u],l); } // cerr << u << ' ' << v << ' ' << l << endl;}
    il void init(int n) {
        for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) dis[i][j]=0x3f3f3f3f3f3f3f3f; 
        for (int i=1; i<=n; ++i) dis[i][i]=0; 
    }
    il void work(int n) {
        for (int k=1; k<=n; ++k) 
        for (int i=1; i<=n; ++i) 
        for (int j=1; j<=n; ++j) cmin(dis[i][j],dis[i][k]+dis[j][k]);
    }
} using flo::dis;
int h; int bas[W+3]; 
il void solve() {
    int tid,w,d,q; cin>>tid>>h>>w>>d>>q;
    for (int i=1; i<=w; ++i) cin>>bas[i];
    for (int i=1; i<=h; ++i) {
        int k; cin>>k;
        for (int a,t; k--; ) cin>>a>>t, G::edge(a,i,t); 
    }
    flo::init(h);
    for (int i=1; i<=w; ++i) {
        for (int a=G::hd[i]; a; a=G::nxt[a])
        for (int b=G::hd[i]; b; b=G::nxt[b])
            flo::edge(G::to[a].fi,G::to[b].fi, G::to[a].se+G::to[b].se);
    }
    flo::work(h);
    // cerr << flo::dis[1][2] << endl;
    for (int qi=1,x,y; qi<=q; ++qi) {
        cin>>x>>y; ll ans=0x3f3f3f3f3f3f3f3f;
        for (int a=G::hd[x]; a; a=G::nxt[a])
        for (int b=G::hd[y]; b; b=G::nxt[b])
            cmin(ans,dis[G::to[a].fi][G::to[b].fi]+ G::to[a].se+G::to[b].se);
#ifdef MYFRE
        assert(ans!=0x3f3f3f3f3f3f3f3f); 
#endif
        cout << ans+bas[x]+bas[y] << '\n';
    }
}
bool Men;
int main() {
// g++ subway.cpp -o subway.exe -O2 -std=c++14 -Wall -Wextra -Wconversion -Wshadow -DMYFRE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef MYFRE
    cerr << "B subway" << endl;
    cerr << "B subway" << endl;
    cerr << "B subway" << endl;
    cerr << "M: " << (db)(&Mbe-&Men)/1024.0/1024 << endl;
#else
#endif 
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
    solve();
    // int testtt; cin>>testtt; for (int ti=1; ti<=testtt; ++ti) solve();
    // int testid, testtt; cin>>testid>>testtt; for (int ti=1; ti<=testtt; ++ti) solve();
#ifdef MYFRE
    cerr << "T: " << (db)clock()/CLOCKS_PER_SEC << endl;
#endif 
}