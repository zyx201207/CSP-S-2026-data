/*
  Author: acmpGu
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
#define fi first
#define se second
#define rep(i, s, t) for(int i = s; i <= t; i++)
#define per(i, s, t) for(int i = t; i >= s; i--)

const ll mod = 998244353;
// const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

/* --- Template End Here --- */

const int MAXN = 5e5 + 9;

int c, n, m, d, q;
ll w[MAXN];
int k[509];
vector<ll> t[509];
vector<pii> lines[MAXN];
ll dis[509][509];

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ifstream cin("subway.in");
    ofstream cout("subway.out");

    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);

    cin >> c >> n >> m >> d >> q;

    rep (i, 1, m) {
        cin >> w[i];
    }

    rep (i, 1, n) {
        cin >> k[i];

        t[i].emplace_back(0);

        rep (j, 1, k[i]) {
            int x, y;

            cin >> x >> y;

            t[i].emplace_back(y);
            lines[x].emplace_back(i, j);
        }
    }

    memset(dis, 0x3f, sizeof(dis));

    rep (i, 1, m) {
        for (pii x1 : lines[i]) {
            for (pii x2 : lines[i]) {
                int l1 = x1.fi, l2 = x2.fi;
                int idx1 = x1.se, idx2 = x2.se;

                if (l1 == l2) {
                    dis[l1][l2] = dis[l2][l1] = 0;
                }

                else {
                    dis[l1][l2] = dis[l2][l1] = min(dis[l1][l2], t[l1][idx1] + t[l2][idx2]);
                }
            }
        }
    }

    rep (k, 1, n) {
        rep (i, 1, n) {
            rep (j, 1, n) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    while (q--) {
        int x, y;
        ll res = infll;

        cin >> x >> y;

        for (pii x1 : lines[x]) {
            for (pii x2 : lines[y]) {
                int l1 = x1.fi, l2 = x2.fi;
                int idx1 = x1.se, idx2 = x2.se;

                res = min(res, w[x] + t[l1][idx1] + dis[l1][l2] + t[l2][idx2] + w[y]);
            }
        }

        cout << res << '\n';
    }

    return 0;

}