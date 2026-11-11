#include <iostream>
#include <vector>
#include <queue>
#define FOR(_name, _start, _end) for (long long _name = _start; _name < _end; _name ++)
using namespace std;

constexpr unsigned long long MAXN = 5005, INF = 0x3f3f3f3f3f3f3f3f;
long long trans[MAXN][MAXN], cnts[MAXN][MAXN], sides[MAXN][MAXN], xs[MAXN], n, d;

struct dijkh {
    long long id, len;

    bool operator<(const dijkh& r) const {
        return len > r.len;
    }
};

void dijk(long long s) {
    priority_queue<dijkh> pq;
    pq.push({s, 0});
    cnts[s][s] = 1;
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        FOR(i, 0, n) {
            if (sides[now.id][i] != 0 && trans[s][i] > now.len + 1) {
                trans[s][i] = now.len + 1;
                pq.push({i, trans[s][i]});
                cnts[s][i] = cnts[s][now.id];
            } else if (sides[now.id][i] != 0 && trans[s][i] == now.len + 1) {
                cnts[s][i] += cnts[s][now.id];
            }
        }
    }
}
long long iabs(long long v) {
    if (v < 0) return -v;
    else return v;
}

void xmain() {
    cin >> n >> d;

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            trans[i][j] = INF;
            cnts[i][j]  = 0;
            sides[i][j] = 0;
        }
    }

    FOR(i, 0, n) {
        cin >> xs[i];
    }

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (i != j && iabs(xs[i] - xs[j]) <= d) {
                sides[i][j] = 1;
            }
        }
    }
    FOR(i, 0, n) {
        dijk(i);
    }

    long long ans = 0;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (i != j && cnts[i][j] == 2) {
                ans++;
            }
        }
    }
    cout << ans / 2 << "\n";
}

int main() {
    freopen("migrate.in",  "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--) xmain();

    return 0;
}

// O(T n^2 log n^2) 24pts? 18:01