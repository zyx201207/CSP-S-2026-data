#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MAXM = 500005;
const int MAXQ = 200005;

typedef pair<int, int> PLI;   // 花费 + 去哪个站点？

int c, n, m, d, q;   //测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数
int w[MAXM];   // 从每个地铁站的地铁口走到站厅需要的时间

struct Plan {
    int s;   // start
    int e;   // end
} plan[MAXQ];

struct Station {
    int road[MAXN];
} ss[MAXM];
vector<int> rr[MAXN];   // 一条线路上的车站

vector<PLI> G[MAXM];   //G[i]代表i站可以到达的站点。分别是站点和路线id
vector<PLI> dist[MAXM];   // 从起点到达当前点的花费。分别是价格和路线id
bool vis[MAXM];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n + 1; j++) ss[i].road[j] = 900000000;
    }
    for (int i = 1; i <= n; i++) {
        int temp;
        std::cin >> temp;

        for (int sta = 1; sta <= temp; sta++) {
            int stanum, cost;
            std::cin >> stanum >> cost;

            ss[stanum].road[i] = cost;
            rr[i].push_back(stanum);
        }
    }
    for (int i = 1; i <= q; i++) cin >> plan[i].s >> plan[i].e;

    for (int i = 1; i <= n; i++) {
        int rrSize = rr[i].size();
        for (int j = 1; j < rrSize; j++) {
            G[rr[i][j - 1]].push_back({rr[i][j], i});
            G[rr[i][j]].push_back({rr[i][j - 1], i});
        }
    }

    for (int ttt = 1; ttt <= q; ttt++) {
        int startSta = plan[ttt].s;
        int endSta = plan[ttt].e;
        int ws = w[startSta];
        int es = w[endSta];
        std::cout << ws + es << "\n";
    }

    return 0;
}
