#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int NR = 505;

vector<int> a[NR];
vector<ll> t[NR];
int k[NR];
ll w[NR];

namespace solve18 {
    ll mp18[2][405][405];

    void solve() {
        int n, m, d, q;

        cin >> n >> m >> d >> q;
        for (int i = 1; i <= m; i++)
            cin >> w[i];
        
        for (int i = 1; i <= n; i++) {
            cin >> k[i];
            a[i].resize(k[i] + 1);
            t[i].resize(k[i] + 1);
            for (int j = 1; j <= k[i]; j++)
                cin >> a[i][j] >> t[i][j];
        }

        memset(mp18, 0x3f, sizeof(mp18));

        int zi, zj;
        for (int way = 1; way <= n; way++) {
            for (int i = 1; i <= k[way]; i++) {
                zi = a[way][i];
                mp18[0][zi][zi] = 0;
                for (int j = i + 1; j <= k[way]; j++) {
                    zj = a[way][j];

                    mp18[0][zi][zj] = min(mp18[0][zi][zj], t[way][i] + t[way][j]);
                    mp18[0][zj][zi] = mp18[0][zi][zj];
                }
            }
        }

        bool flag;
        for (int k = 1; k <= m; k++) {
            flag = k & 1;
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= m; j++) {
                    if (mp18[!flag][i][j] > mp18[!flag][i][k] + mp18[!flag][k][j]) {
                        mp18[flag][i][j] = mp18[!flag][i][k] + mp18[!flag][k][j];
                    }
                    else
                        mp18[flag][i][j] = mp18[!flag][i][j];
                }
            }
        }

        int x, y;
        while (q--) {
            cin >> x >> y;
            printf("%lld\n", mp18[m & 1][x][y] + w[x] + w[y]);
        }
    }
}

namespace solve911 {
    struct edgeT {
        int u, v;
        ll w;
    };
    ll mp911[1005][1005];

    void solve() {
        int n, m, d, q;

        cin >> n >> m >> d >> q;
        for (int i = 1; i <= m; i++)
            cin >> w[i];

        for (int i = 1; i <= n; i++) {
            cin >> k[i];
            a[i].resize(k[i] + 1);
            t[i].resize(k[i] + 1);
            for (int j = 1; j <= k[i]; j++)
                cin >> a[i][j] >> t[i][j];
        }

        vector<edgeT> E;
        edgeT tmp_edge;
        for (int way = 1; way <= n; way++) {
            if (k[way] == 2) {
                tmp_edge = edgeT{a[way][1], a[way][2], t[way][1] + t[way][2]};
                E.emplace_back(tmp_edge);
                swap(tmp_edge.u, tmp_edge.v);
                E.emplace_back(tmp_edge);
            }
        }
        memset(mp911, 0x3f, sizeof(mp911));

        bool flag;
        for (int x = 1; x <= m; x++) {
            mp911[x][x] = 0;
            for (int k = 1; k <= m; k++) {
                flag = false;
                for (edgeT e : E) {
                    if (mp911[x][e.u] + e.w < mp911[x][e.v]) {
                        mp911[x][e.v] = mp911[x][e.u] + e.w;
                        flag = true;
                    }
                }
                if (!flag) break;
            }
        }

        int x, y;
        while (q--) {
            cin >> x >> y;
            printf("%lld\n", mp911[x][y] + w[x] + w[y]);
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;

    cin >> c;
    
    if (c <= 8)
        solve18::solve();
    else if (c <= 11)
        solve911::solve();
    return 0;
}