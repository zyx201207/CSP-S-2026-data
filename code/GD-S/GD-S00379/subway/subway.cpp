#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _iter(it,a) for (auto it=a.begin();it!=a.end();++it)
#define _riter(it,a) for (auto it=a.rbegin();it!=a.rend();++it)
#define _all(a) (a).begin(),(a).end()
#define _rall(a) (a).rbegin(),(a).rend()

#define i32 signed
#define i64 long long
#define u32 unsigned
#define u64 unsigned long long

typedef pair<int,int> pii;

const int N=505;
const int M=500005;
const int inf=1e18;

int c,n,m,d,Q;
int e[M],w[M],ne[M],h[N],tot;
int es[N][N];
int arr[M];
vector<pii> vec[M];
priority_queue<pii,vector<pii>,greater<pii>> q;
int dis[N][N];
bool flag[N];

inline void add(int a,int b,int c) {
    e[tot]=b,w[tot]=c,ne[tot]=h[a],h[a]=tot++;
}

inline void dijkstra(int s) {
    _rep(i,1,n) flag[i]=false,dis[s][i]=inf;
    q.emplace(pii{dis[s][s]=0,s});
    while (!q.empty()) {
        auto tp=q.top(); q.pop();
        int u=tp.second;
        if (flag[u]) continue;
        flag[u]=true;
        _graph(i,u) if (dis[s][e[i]]>dis[s][u]+w[i]) q.emplace(pii{dis[s][e[i]]=dis[s][u]+w[i],e[i]});
    }
}

i32 main() {
    // FRR("subway7.in");
    // FRW("my.out");
    FRR("subway.in");
    FRW("subway.out");
    memset(h,-1,sizeof(h));
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&Q);
    _rep(i,1,m) scanf("%lld",&arr[i]);
    _rep(i,1,n) {
        int k;
        scanf("%lld",&k);
        while (k--) {
            int a,t;
            scanf("%lld %lld",&a,&t);
            vec[a].emplace_back(pii{i,t});
        }
    }
    _rep(i,1,n) _rep(j,1,n) es[i][j]=inf;
    _rep(i,1,m) _rep(x,0,(int)vec[i].size()-1) _rep(y,0,(int)vec[i].size()-1) {
        es[vec[i][x].first][vec[i][y].first]=es[vec[i][y].first][vec[i][x].first]=min(es[vec[i][x].first][vec[i][y].first],vec[i][x].second+vec[i][y].second);
    }
    // _rep(i,1,n) _rep(j,1,n) if (i!=j) {
    //     printf("es[%lld][%lld] = %lld\n",i,j,es[i][j]);
    // }
    _rep(i,1,n) _rep(j,1,n) if (i!=j && es[i][j]!=inf) add(i,j,es[i][j]);
    _rep(i,1,n) dijkstra(i);
    while (Q--) {
        int x,y;
        scanf("%lld %lld",&x,&y);
        int ans=inf;
        _rep(i,0,(int)vec[x].size()-1) _rep(j,0,(int)vec[y].size()-1) {
            ans=min(ans,arr[x]+vec[x][i].second+dis[vec[x][i].first][vec[y][j].first]+vec[y][j].second+arr[y]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

/*
14:57 start coding
15:15 done
*/