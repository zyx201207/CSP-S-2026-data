#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T> void chkmax(T &x, T y) {if (x < y) x = y;}
template<typename T> void chkmin(T &x, T y) {if (x > y) x = y;}
#define UP(x,y,z) for (int x = y; x <= z; ++x)

namespace imc {
    constexpr int N = 1005;
    int f[N][N][2], g[N][N][2];
    vector<int> G[N];
    int n,k;
    void dfs(int u, int fa) {
        if (!G[u].size()) {
            f[u][1][0] = 1;
            g[u][0][0] = 0;
            return;
        }
        for (const int &v : G[u]) if (v != fa) {
            dfs(v, u);
            UP(i,0,k) g[u][i][0];
        }
    }
    void main() {
        cin >> n >> k;
        UP(i,2,n) {
            int u, v; cin >> u >> v;
        }
        int m = (n / 2);
        int p = (m+1) / 2;

        cout << (n / 2) - k << '\n';
    }
}

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1,c;
    cin >> c >> T;
    while (T--) {
        imc::main();
    }
}