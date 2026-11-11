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

const int MAXN = 1e6 + 9;

int C, T;
int n, k;
vector<int> e[MAXN];
int fa[MAXN];
vector<int> build;
queue<int> q;
int dis[19][MAXN];
bool vis[MAXN];
int dist[MAXN];
bool mp[MAXN];

int Find (int cur) {

    if (fa[cur] == cur) {
        return cur;
    }

    return fa[cur] = Find(fa[cur]);

}

void Merge (int x, int y) {

    int fx = Find(x);
    int fy = Find(y);

    if (fx != fy) {
        fa[fx] = fy;
    }

}

void Bfs (int idx) {

    int s = build[idx];

    rep (i, 1, n) {
        vis[i] = 0;
        dis[idx][i] = inf;
    }

    q.push(s);
    dis[idx][s] = 0;

    while (!q.empty()) {
        int cur = q.front();

        q.pop();

        vis[cur] = 1;

        for (int to : e[cur]) {
            if (vis[to]) {
                continue;
            }

            if (dis[idx][cur] + 1 < dis[idx][to]) {
                dis[idx][to] = dis[idx][cur] + 1;
                q.push(to);
            }
        }
    }

}

void Solve () {

    int res = inf;

    cin >> n >> k;

    rep (i, 1, n) {
        e[i].clear();
    }

    rep (i, 1, n - 1) {
        int u, v;

        cin >> u >> v;

        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    if (C == 13 || C == 14) {
        if (k == n) {
            res = 0;
        }
            
        else if (k >= (n + 1) / 2) {
            res = 1;
        }

        else {
            if (n % 4 == 3) {
                if (k & 1) {
                    res = ((n + 1) / 4 - (k - 1) / 2 + 1) / 2 + 1;
                }

                else {
                    res = ((n + 1) / 4 - k / 2 + 1) / 2 + 1;
                }
            }

            else {
                if (k & 1) {
                    res = ((n + 3) / 4 - (k - 1) / 2 + 1) / 2;
                }

                else {
                    res = ((n + 3) / 4 - k / 2 + 1) / 2;
                }
            }
        }
    }

    else if (k == 1) {
        rep (p, 1, n) {
            build = {p};
                
            rep (j, 1, n) {
                dist[j] = inf;
            }

            rep (idx, 0, build.size() - 1) {
                Bfs(idx);

                rep (x, 1, n) {
                    dist[x] = min(dist[x], dis[idx][x]);
                }
            }

            int r = 0;

            rep (x, 1, n) {
                r = max(r, dist[x]);
            }

            res = min(res, r);
        }
    }

    else if (k == 2) {
        rep (p, 1, n) {
            rep (q, 1, n) {
                if (p == q) {
                    continue;
                }

                build = {p, q};
                
                rep (j, 1, n) {
                    dist[j] = inf;
                }

                rep (idx, 0, build.size() - 1) {
                    Bfs(idx);

                    rep (x, 1, n) {
                        dist[x] = min(dist[x], dis[idx][x]);
                    }
                }

                int r = 0;

                rep (x, 1, n) {
                    r = max(r, dist[x]);
                }

                res = min(res, r);
            }
        }
    }

    else if (k <= 10) {
        rep (i, pow(2, k) - 1, pow(2, n) - 1) {
            build.clear();

            rep (j, 1, n) {
                dist[j] = inf;
                fa[j] = j;
                mp[j] = 0;

                if ((i >> (j - 1)) & 1) {
                    build.emplace_back(j);
                }
            }

            if (build.size() != k) {
                continue;
            }

            rep (idx, 0, build.size() - 1) {
                Bfs(idx);

                rep (x, 1, n) {
                    dist[x] = min(dist[x], dis[idx][x]);
                }
            }

            rep (idx, 0, build.size() - 1) {
                for (int y : build) {
                    int x = build[idx];

                    if (x != y && dis[idx][y] == 1) {
                        Merge(x, y);
                    }
                }
            }

            int scc = 0;

            for (int x : build) {
                int fx = Find(x);

                if (!mp[fx]) {
                    scc++;
                }

                mp[fx] = 1;
            }

            if (scc > 2) {
                continue;
            }

            int r = 0;

            rep (x, 1, n) {
                r = max(r, dist[x]);
            }

            res = min(res, r);
        }
    }

    else {
        if (n == k) {
            res = 0;
        }

        else if (n >= k / 2) {
            res = 1;
        }

        else {
            res = 2;
        }
    }

    cout << res << '\n';

}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);

    cin >> C >> T;

    while (T--) {
        Solve();
    }

    return 0;

}