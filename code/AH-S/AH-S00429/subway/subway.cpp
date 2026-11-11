/*
Using Chinese language is too eye-catching,so I have to use zh and English.

君应有语：渺万里层云，千山暮雪，只影向谁去。

I'm gonna have many whk examinations.
It means I'll be away from OI for a long time
The next year is very important.
Good luck to me.

The game was over and the player woke up from the dream.
And the player started a new dream.
The player dreamed again,dreamed better.
The player is the universe,and the player is the love.
You're the player.
Wake up.

Senbon Zakura.

KDR:53.17

Author by NekoKami 猫之神明.
(You cannot find me in luogu because my luogu id is not this,I don't wanna tell you.)
*/
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define int long long
//#define OI
using namespace std;

const int N = 1e6 + 10;
int c, n, m, d, q;
int w[N], dis[N];
struct edge{
    int nxt;
    int t;
};
vector<edge> g[N];
void dfs(int u, int fa, int last, int cnt) {
    if (cnt > d) return ;
    for (edge e : g[u]) {
        if (e.nxt == fa) continue;
        dis[e.nxt] = min(dis[e.nxt], dis[u] + last + e.t);
        dfs(e.nxt, u, e.t, cnt + 1);
    }
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef OI
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
#endif
    cin >> c >> n >> m >> d >> q;
    rep (i, 1, m) cin >> w[i];
    rep (i, 1, n) {
        int k;
        cin >> k;
        rep (j, 1, k) {
            int a, b;
            cin >> a >> b;
            g[i].push_back((edge){a, b});
            g[a].push_back((edge){i, b});
        }
    }
    while (q--) {
        int st, ed;
        cin >> st >> ed;
        memset(dis, 0x3f, sizeof(dis));
        dis[st] = 0;
        dfs(st, false, false, true);
        cout << dis[ed] + w[st] + w[ed] << "\n";
    }
    return 0;
}
