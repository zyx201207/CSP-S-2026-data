#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <queue>
using namespace std;
using ui32 = unsigned int;
using big = long long;
using ui64 = unsigned big;
using bigf = long double;
constexpr const big INF = 1e18;
constexpr const big mod = 998244353;
constexpr const bigf EPS = 1e-8;

constexpr const int N = 5e5 +5, M = 500 +5, D = 20 +5;

int n, m, d, q;
big G[M][M], w[N], t[N][D];
int line[N][D], cnt[N];

inline void floyd() {
    for(int k=1;k<=m;k++) {
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=m;j++) {
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
}

inline void solve() {
    cin>>m>>n>>d>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=m;i++) {
        int k;cin>>k;
        for(int j=1;j<=k;j++) {
            int v;big w;cin>>v>>w;
            ++cnt[v];
            line[v][cnt[v]] = i, t[v][cnt[v]] = w;
        }
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=m;j++) {
            if(i!=j) G[i][j] = INF;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=cnt[i];j++) {
            for(int k=1;k<=cnt[i];k++) {
                G[line[i][j]][line[i][k]] = min(G[line[i][j]][line[i][k]], t[i][j]+t[i][k]);
            }
        }
    }
    floyd();
    for(int i=1;i<=q;i++) {
        int u,v;cin>>u>>v;
        big ans = INF;
        for(int i=1;i<=cnt[u];i++) {
            for(int j=1;j<=cnt[v];j++) {
                ans = min(ans, G[line[u][i]][line[v][j]] + t[u][i]+t[v][j]);
            }
        }
        cout<<ans+w[u]+w[v]<<"\n";
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int c; cin >> c;
    solve();
    return 0;
}
