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

/* --- Template End Here --- */

const int MAXN = 2e6 + 9;

int C, T;
ll n, d;
ll x[MAXN];
vector<int> e[MAXN];
queue<int> q;
bool vis[MAXN];
int dis[5009][5009];
int cnt[5009][5009];
int pre[MAXN];
int suf[MAXN];

void Bfs (int s) {

    rep (i, 1, n) {
        vis[i] = 0;
        dis[s][i] = inf;
        cnt[s][i] = 0;
    }

    q.push(s);
    dis[s][s] = 0;
    cnt[s][s] = 1;

    while (!q.empty()) {
        int cur = q.front();

        q.pop();

        vis[cur] = 1;

        for (int to : e[cur]) {
            if (vis[to]) {
                continue;
            }

            if (dis[s][cur] + 1 < dis[s][to]) {
                dis[s][to] = dis[s][cur] + 1;
                q.push(to);
            }

            if (dis[s][cur] + 1 == dis[s][to]) {
                cnt[s][to] += cnt[s][cur];
            }
        }
    }

}

void Solve () {

    int res = 0;
    ll diff = 0;

    cin >> n >> d;

    rep (i, 1, n) {
        cin >> x[i];
        e[i].clear();
    }

    if (C <= 10) {
        rep (i, 1, n) {
            rep (j, 1, i - 1) {
                if (abs(x[i] - x[j]) <= d) {
                    e[i].emplace_back(j);
                    e[j].emplace_back(i);
                }
            }
        }

        rep (i, 1, n) {
            Bfs(i);
        }

        rep (i, 1, n) {
            rep (j, 1, i) {
                if (cnt[i][j] == 2) {
                    res++;
                }
            }
        }
    }
    
    else if (C <= 12) {
        diff = x[2] - x[1];

        if (diff * 2 <= d) {
            res = max(0ll, n - d / diff * 2ll + 1);
        }
    }

    cout << res << '\n';

}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);

    cin >> C >> T;

    while (T--) {
        Solve();
    }

    return 0;

}