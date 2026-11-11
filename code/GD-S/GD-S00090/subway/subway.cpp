#include<bits/stdc++.h>
using namespace std;  typedef long long LL; 
#define rep(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1<=__##_1##__; ++_1)
#define repo(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1<__##_1##__; ++_1)
#define reb(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1>=__##_1##__; --_1)
const int N=504, M=500004, K=0, E=1000008, H=500508, Q=100008; 
const LL INF2=0x3F3F3F3F3F3F3F3FLL;
typedef pair<int, int> pii;
int n, m, q, h, a[M], X[Q], Y[Q];  LL ans[Q];
int hea[H], nex[E], to[E], wg[E], cte;
void ae(int x, int y, int z) { ++cte, nex[cte]=hea[x], hea[x]=cte, to[cte]=y, wg[cte]=z; }
struct node { int id;  LL z; };  bool operator>(const node&A, const node&B) { return A.z>B.z; }
LL dis[H];
void dij(int s) {
    rep(i,1,h) dis[i]=INF2;
    priority_queue<node, vector<node>, greater<node> > pq;
    pq.push(node{s,0}), dis[s]=0;
    while(!pq.empty()) {
        int x=pq.top().id;  LL zz=pq.top().z;  pq.pop();
        if(zz>dis[x]) continue;
        for(int it=hea[x]; it; it=nex[it]) {
            int y=to[it];  LL z=wg[it];  if(zz+z<dis[y]) pq.push(node{y, dis[y]=zz+z});
        }
    }
}

bool __main() {
    int _=0;  cin>>n>>m>>_>>q;  h=n+m;
    rep(i,1,m) cin>>a[i];
    rep(i,m+1,h) {
        int k=0;  cin>>k;
        rep(eid, 1, k) { int y=0, z=0;  cin>>y>>z;  ae(i,y,z), ae(y,i,z); }
    }
    rep(i,1,q) cin>>X[i]>>Y[i], ans[i]=INF2;
    // Dot 1~@m: train station halls, Dot @m+1~@m+@n: the lines
    rep(i,m+1,h) {
        dij(i);
        rep(j,1,q) ans[j]=min(ans[j], dis[X[j]]+dis[Y[j]]);
    }
    rep(i,1,q) cout<<ans[i]+a[X[i]]+a[Y[i]]<<'\n';
    return 0;
}

int main() {
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout); // PAY ATTENTION!! 
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
    int _=1, __=0; cin>>__; /* cin>>_; */ for(; _>0; --_) if(__main()) return 0;
    return 0;
}