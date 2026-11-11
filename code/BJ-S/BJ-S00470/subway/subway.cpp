#include <climits>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
struct StationNode {
    ll line, time;
};
struct DistNode {
    ll time, line;
};

const ll MAXM = 500005;
const ll MAXN = 505;
const ll MAXK = 500005;

ll c, n, m, d, q;
ll w[MAXM];
ll k[MAXN];
vector<ll> line[MAXN];
vector<StationNode> station[MAXM];
ll t[MAXM][MAXN];
DistNode dist[MAXM];
queue<ll> pq;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);

    for (ll i = 1; i <= m; ++i) {
        scanf("%lld", &w[i]);
    }

    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &k[i]);

        for (ll j = 1; j <= k[i]; ++j) {
            ll tmp, time;
            scanf("%lld %lld", &tmp, &time);
            line[i].push_back(tmp);
            station[tmp].push_back({i, time});
            t[tmp][i] = time;
        }
    }

    while (q--) {
        ll x, y;
        scanf("%lld %lld", &x, &y);

        for (ll i = 1; i <= m; ++i) {
            dist[i].time = LLONG_MAX;
            dist[i].line = -1;
        }

        pq.push(x);
        dist[x].time = 0;

        while (pq.empty() == false) {
            ll u = pq.front();
            pq.pop();
            
            for (auto i : station[u]) {
                for (auto j : line[i.line]) {
                    if (i.line != dist[u].line || dist[u].line != -1) {
                        if (i.time + t[j][i.line] + dist[u].time < dist[j].time) {
                            dist[j].time = i.time + t[j][i.line] + dist[u].time;
                            dist[j].line = i.line;
                            pq.push(j);
                        }
                    }
                }
            }
        }

        printf("%lld\n", w[x] + w[y] + dist[y].time);
    }

    return 0;
}