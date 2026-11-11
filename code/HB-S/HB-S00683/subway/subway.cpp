#include <bits/stdc++.h>
using namespace std;

const int MxM = 500005; // max m
const int MxN = 515; // max n

int c; // 测试点编号
int n; // 地铁线路数
int m; // 地铁站数
int d; // 每个地铁站最多被几条线路经过
int q; // 出行计划数
int w[MxM]; // 从每个地铁站的地铁口走到站厅需要的时间
int mp[MxN][MxN];
vector <pair <int, int> > sta[MxM];
int x, y;

struct node {
    long long nw, tm;
} nw, tn;

long long bfs(int f, int t) {
    long long vis[MxN];
    long long mn = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++) vis[i] = LONG_LONG_MAX;
    queue <node> qu;
    tn.nw = f;
    tn.tm = 0;
    qu.push(tn);
    while (!qu.empty()) {
        nw = qu.front();
        qu.pop();
        vis[nw.nw] = nw.tm;
        if (nw.nw == t) {
            if (c >= 12 && c <= 19) return nw.tm;
            if (nw.tm < mn) mn = nw.tm;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (mp[nw.nw][i]) {
                tn.nw = i;
                tn.tm = nw.tm + mp[nw.nw][i];
                if (tn.tm < vis[i]) qu.push(tn);
            }
        }
    }
    return mn;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) scanf("%d", w + i);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        int a, t;
        for (int j = 1; j <= k; j++) {
            scanf("%d%d", &a, &t);
            sta[a].push_back({i, t});
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < sta[i].size(); j++) {
            for (int k = 0; k < sta[i].size(); k++) {
                if (j == k) continue;
                mp[sta[i][j].first][sta[i][k].first] = sta[i][j].second + sta[i][k].second;
            }
        }
    }
    for (int dc = 1; dc <= q; dc++) {
        scanf("%d%d", &x, &y);
        long long mn = LONG_LONG_MAX;
        for (int i = 0; i < sta[x].size(); i++) {
            for (int j = 0; j < sta[y].size(); j++) {
                int il = sta[x][i].first;
                int jl = sta[y][j].first;
                long long lll = bfs(il, jl) + sta[x][i].second + sta[y][j].second;
                if (lll < mn) mn = lll;
            }
        }
        printf("%lld\n", mn + w[x] + w[y]);
    }
    return 0;
} // 48?