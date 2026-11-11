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
const int N=2e6; 
namespace T {
    const int W=N*2; int ban=0, mxp;
    int hd[W+3], nxt[W+3]; int to[W+3]; int pt=0;
    il void edge(int u, int v) {
        ++pt, to[pt]=v, nxt[pt]=hd[u], hd[u]=pt; 
        swap(u,v);
        ++pt, to[pt]=v, nxt[pt]=hd[u], hd[u]=pt; 
    }
    int fa[N+3], len[N+3], dep[N+3], dfc, dfn[N+3];
    il void dfs1(int u, int _f=0) {
        dfn[++dfc]=u, dep[u]=dep[fa[u]=_f]+1, dep[u]>dep[mxp]?mxp=u,1:0, len[u]=0; 
        for (int ei=hd[u],v; v=to[ei], ei; ei=nxt[ei]) if (v!=ban&&v!=_f)
            dfs1(v,u), cmax(len[u],len[v]+1);
    }
}
int K;
priority_queue<pii> pq;
il void work(int _rt, int ty, int*ans) {
    while (sz(pq)) pq.pop();
    if (ty) {
        int rtl=_rt, rtr=T::fa[_rt];
        T::dfc=0, T::dfs1(rtl,rtr);
        for (int _i=1,u; u=T::dfn[_i], _i<=T::dfc; ++_i) u!=rtl&&u!=rtr?pq.push({T::len[u],u}),1:0;
        T::dfc=0, T::dfs1(rtr,rtl);
        for (int _i=1,u; u=T::dfn[_i], _i<=T::dfc; ++_i) u!=rtl&&u!=rtr?pq.push({T::len[u],u}),1:0;
        ans[0]=T::len[rtl]+1, ans[1]=T::len[rtl];
        for (int u,i=1; i<=K&&sz(pq); ++i) {
            u=pq.top().se, pq.pop();
            if (sz(pq)&&pq.top().fi==T::len[u]) 
                ans[i]=ans[i-1];
            else 
                ans[i]=ans[i-1]-1;
            for (int ei=T::hd[u],v; v=T::to[ei], ei; ei=T::nxt[ei]) if (v!=T::fa[u]) 
                pq.push({T::len[v],v});
        }
    } else { int rt=_rt;
        T::dfc=0, T::dfs1(rt,0);
        for (int _i=1,u; u=T::dfn[_i], _i<=T::dfc; ++_i) u!=rt?pq.push({T::len[u],u}),1:0;
        ans[0]=T::len[rt]; 
        for (int u,i=1; i<=K&&sz(pq); ++i) {
            u=pq.top().se, pq.pop();
            if (sz(pq)&&pq.top().fi==T::len[u]) 
                ans[i]=ans[i-1];
            else 
                ans[i]=ans[i-1]-1;
            for (int ei=T::hd[u],v; v=T::to[ei], ei; ei=T::nxt[ei]) if (v!=T::fa[u]) 
                pq.push({T::len[v],v});
        }
    }
}
int ans0[N+3], ans1[N+3];
il void solve() {
    int n; cin>>n>>K, T::pt=0, T::ban=0;
    for (int i=1; i<=n; ++i) T::hd[i]=0;
    for (int ei=1,u,v; ei<n; ++ei) cin>>u>>v, T::edge(u,v);
    int ans=n;
    for (int u=1, s,t,m,da,de; u<=n; ++u) for (int ei=T::hd[u],v; v=T::to[ei], ei; ei=T::nxt[ei]) if (u<v) {
        // cerr << u << ' ' << v << endl;
        T::ban=v, T::mxp=0, T::dfc=0, T::dfs1(u,0), s=T::mxp, T::dfc=0, T::dfs1(s,0), t=T::mxp;
        m=t; for (int i=T::len[s]>>1; i--; m=T::fa[m]);
        // cerr << s << ' ' << t << ' ' << T::len[s] << ' ' << m << endl;
        da=T::len[s], work(m,T::len[s]&1,ans0), swap(u,v);
        // cerr << ' ' << ans0[0] << ' ' << ans0[1] << ' ' << ans0[2] << endl;

        T::ban=v, T::mxp=0, T::dfc=0, T::dfs1(u,0), s=T::mxp, T::dfc=0, T::dfs1(s,0), t=T::mxp;
        m=t; for (int i=T::len[s]>>1; i--; m=T::fa[m]);
        // cerr << s << ' ' << t << ' ' << T::len[s] << ' ' << m << endl;
        de=T::len[s], work(m,T::len[s]&1,ans1), swap(u,v);
        // cerr << ' ' << ans1[0] << ' ' << ans1[1] << ' ' << ans1[2] << endl;

        // cmin(ans,max(da,ans1[K-2])); 
        // cmin(ans,max(ans0[K-2],de)); 
        for (int j=0; j<=K-2; ++j) cmin(ans, max(ans0[j],ans1[K-2-j]));
        // cerr << "ans: " << ans << endl; 
    }
    cout << ans << '\n';
}
bool Men;
int main() {
// g++ hub.cpp -o hub.exe -O2 -std=c++14 -Wall -Wextra -Wconversion -Wshadow -DMYFRE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef MYFRE
    cerr << "D hub" << endl;
    cerr << "D hub" << endl;
    cerr << "D hub" << endl;
    cerr << "M: " << (db)(&Mbe-&Men)/1024.0/1024 << endl;
#else
#endif 
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
    // solve();
    // int testtt; cin>>testtt; for (int ti=1; ti<=testtt; ++ti) solve();
    int testid, testtt; cin>>testid>>testtt; for (int ti=1; ti<=testtt; ++ti) solve();
#ifdef MYFRE
    cerr << "T: " << (db)clock()/CLOCKS_PER_SEC << endl;
#endif 
}