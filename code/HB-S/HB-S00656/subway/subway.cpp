#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define lowbit(op) (op&-op)
inline pii operator + (const pii &x,const pii &y) {return {x.f+y.f,x.s+y.s};}
inline pii operator - (const pii &x,const pii &y) {return {x.f-y.f,x.s-y.s};}
inline int operator ^ (const pii &x,const pii &y) {return x.f*y.s-x.s*y.f;}

const int maxn=510,maxm=500010;
const ll inf=1e18;

int c,n,m,d,q,k,u,v;

int w[maxm];
vector<pii> sub[maxm];
ll dis[maxn][maxn],ans;
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) cin >> u >> v,sub[u].push_back({i,v});
    }
    for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++) dis[i][j]=dis[j][i]=inf;
    for (int i = 1; i <= m; i++) {
        int len=sub[i].size();
        for (int j = 0; j < len; j++) 
            for (int z = j+1; z < len; z++) 
                dis[sub[i][j].f][sub[i][z].f]=min(dis[sub[i][j].f][sub[i][z].f],0ll+sub[i][j].s+sub[i][z].s);
    }
    for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++) dis[i][j]=dis[j][i]=min(dis[i][j],dis[j][i]);
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            for (int z = 1; z <= n; z++) 
                dis[i][z]=min(dis[i][j]+dis[j][z],dis[i][z]);
    while(q--) {
        cin >> u >> v;ans=inf;
        for (pii j:sub[u]) 
            for (pii z:sub[v]) 
                ans=min(ans,dis[j.f][z.f]+j.s+z.s);
        cout << ans+w[u]+w[v] << '\n';
    }
    return 0;
}