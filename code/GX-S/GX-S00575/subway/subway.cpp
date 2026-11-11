#include <iostream>
#include <vector>
#define FOR(_name, _start, _end) for (long long _name = _start; _name < _end; _name ++)
using namespace std;

constexpr unsigned long long MAXM = 500005, MAXN = 505, MAXD = 23, INF = 0x3f3f3f3f3f3f3f3f;

struct help0 {
    long long line, walkt;
};
vector<help0> tostat[MAXM];

long long c, n, m, d, q, tohall[MAXM];
long long trans[MAXN][MAXN];

void dijk(long long s) {
    vector<bool> vising(n, true);
    while (true) {
        long long mins = -1, minv = INF;
        FOR(i, 0, n) {
            if (vising[i] && trans[s][i] < minv) {
                mins = i;
                minv = trans[s][i];
            }
        }
        if (mins == -1) break;
        vising[mins] = false;
        FOR(i, 0, n) {
            if (trans[s][i] > trans[s][mins] + trans[mins][i]) {
                trans[s][i] = trans[s][mins] + trans[mins][i];
                vising[i] = true;
            }
        }
    }
}

int main() {
    freopen("subway.in",  "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> d >> q;

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            trans[i][j] = INF;
        }
    }

    FOR(i, 0, m) {
        cin >> tohall[i];
    }

    FOR(i, 0, n) {
        long long k;
        cin >> k;
        FOR(j, 0, k) {
            long long toto, toti;
            cin >> toto >> toti;
            toto--;
            tostat[toto].push_back({i, toti});
        }
    }

    FOR(i, 0, m) {
        for (auto v0: tostat[i]) {
            for (auto v1: tostat[i]) {
                if (v0.line == v1.line) continue;
                trans[v0.line][v1.line] = min(trans[v0.line][v1.line], v0.walkt + v1.walkt);
                trans[v1.line][v0.line] = min(trans[v1.line][v0.line], v0.walkt + v1.walkt);
            }
        }
    }
    FOR(i, 0, n) {
        trans[i][i] = 0;
    }

    FOR(i, 0, n) {
        dijk(i);
    }

    FOR(i, 0, q) {
        long long u, v;
        cin >> u >> v;
        u--, v--;
        long long ans = INF;
        for (auto v0: tostat[u]) {
            for (auto v1: tostat[v]) {
                ans = min(ans, trans[v0.line][v1.line] + v0.walkt + v1.walkt);
            }
        }
        cout << (ans + tohall[u] + tohall[v]) << "\n";
    }

    return 0;
}
// O(md^2 + n^3 + qd^2) 100pts? 16:59