#include <bits/stdc++.h>
#define rep(i,j,n) for (int i=j;i<=n;++i)
#define rrep(i,j,n) for (int i=n;i>=j;--i)
#define file(name) \
freopen(#name".in","r",stdin); \
freopen(#name".out","w",stdout);
using namespace std;
typedef long long ll;
constexpr int N = 5e5+50;
ll dis[510][510];
ll w[N];
typedef pair<int,ll> pll;
vector<pll> blg[N];
unordered_map<int,ll> mp[N];
int c,n,m,d,q;
int main() {
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(0);
    file(subway)
    memset(dis,0x3f,sizeof(dis));
    cin >> c >> n >> m >> d >> q;
    rep(i,1,m) cin >> w[i];
    rep(i,1,n) {
        int k;cin >> k;
        rep(j,1,k) {
            int a,t;cin >> a >> t;
            mp[a][i] = t;
            blg[a].push_back({i,t});
        }
    }
    rep(i,1,m) {
        int siz=blg[i].size();
        if (siz) {
            rep(j,0,siz-1) rep(k,j+1,siz-1) {
                int x = blg[i][j].first,y=blg[i][k].first;
                dis[x][y]=dis[y][x]=min(dis[x][y],blg[i][j].second+blg[i][k].second);
            }
        }
    }
    rep(i,1,n) dis[i][i]=0;
    rep(k,1,n) rep(i,1,n) rep(j,1,n) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    rep(i,1,q) {
        int x,y;cin >> x >> y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for (auto &d:blg[x]) for (auto &t:blg[y]) ans = min(ans,mp[x][d.first]+mp[y][t.first]+dis[d.first][t.first]);
        cout << ans + w[x]+w[y] << '\n';
    }

    cerr << (double)clock()/CLOCKS_PER_SEC;

    return 0;
}