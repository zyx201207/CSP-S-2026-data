#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (b); i >= (a); i--)
#define rp(i, a) for(int i = 1; i <= (a); i++)
#define pr(i, a) for(int i = (a); i >= 1; i--)
#define ll long long
#define db double
#define pb push_back
#define si(x) (int)(x).size()
#define ft first
#define sd second
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define endl '\n'
const ll Mod = 1000000007ll;
//const ll Mod = 998244353ll;
const ll B = 13131ll;

int c, n, m, d, q;
ll w[500005];
vector<pil> edge[500005];
ll dis[505][505];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    rp(i, m) {
        cin >> w[i];
    }
    rp(i, n) {
        int k;
        cin >> k;
        rp(j, k) {
            int a, t;
            cin >> a >> t;
            edge[a].push_back({i, t});
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    rp(i, n) {
        dis[i][i] = 0;
    }
    rp(i, m) {
        rep(j, 0, si(edge[i]) - 1) {
            rep(k, j + 1, si(edge[i]) - 1) {
                ll& x = dis[edge[i][j].ft][edge[i][k].ft];
                ll& y = dis[edge[i][k].ft][edge[i][j].ft];
                x = min(x, edge[i][j].sd + edge[i][k].sd);
                y = min(y, edge[i][j].sd + edge[i][k].sd);
//                cout << edge[i][j].ft << ", " << edge[i][k].ft << ", val = " << edge[i][j].sd + edge[i][k].sd << endl;
            }
        }
    }
//    rp(i, n) {
//        rp(j, n) {
//            cout << "dis " << i << " " << j << " = " << dis[i][j] << endl;
//        }
//    }
//    cout << "----------" << endl;
    rp(k, n) {
        rp(i, n) {
            rp(j, n) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
//    rp(i, n) {
//        rp(j, n) {
//            cout << "dis " << i << " " << j << " = " << dis[i][j] << endl;
//        }
//    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        ll ans = LLONG_MAX;
        rep(i, 0, si(edge[x]) - 1) {
            rep(j, 0, si(edge[y]) - 1) {
//                cout << "(" << edge[x][i].ft << ", " << edge[y][i].ft << "): " << edge[x][i].sd << " + " << dis[edge[x][i].ft][edge[y][i].ft] << " + " << edge[y][i].sd << endl;
                ans = min(ans, edge[x][i].sd + dis[edge[x][i].ft][edge[y][j].ft] + edge[y][j].sd);
            }
        }
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}
