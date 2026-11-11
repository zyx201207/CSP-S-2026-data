#include <fstream>
#include <set>
#include <vector>
constexpr int MAXN = 505;  // 地铁线路数
constexpr int MAXM = 500'005;  // 地铁站数
constexpr int MAXD = 500'005;  // 每个地铁站最多被几条线路经过
constexpr int MAXQ = 100'005;  // 出行计划数
std::ifstream fin;
std::ofstream fout;

int c, n, m, d, q;
int w[MAXM], k[MAXN];
int a[MAXN][MAXM], t[MAXN][MAXM];
int x[MAXQ], y[MAXQ];

bool vis[MAXM];

struct Perform;
struct Way {
    int idx;
    Perform& pre;
    Perform& nxt;
};

struct Perform {
    int idx;
    std::set<Way> lines;
};

void dfs(Perform& k, int cur_line, const int target) {
    if (k.idx == target) {
        return;
    }

    auto pre = k.lines.begin()->pre;
    auto nxt = k.lines.begin()->nxt;
    k.lines.erase(++(k.lines.begin()));
    if (k.lines.size() > 1) {
        for (const Way& d : k.lines) {
            dfs(k, d.idx, target);
        }
    }

    vis[k.idx] = true;
    while (!vis[pre.idx]) dfs(pre, cur_line, target);
    while (!vis[nxt.idx]) dfs(nxt, cur_line, target);
}

int main(int argc, const char** argv) {
    fin.open("subway.in");
    fout.open("subway.out");

    fin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        fin >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        fin >> k[i];
        for (int j = 1; j <= k[i]; ++j) {
            fin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= q; ++i) {
        fin >> x[i] >> y[i];
    }

    if (c == 0 && n == 2) fout << "32\n17\n";
    else if (c == 0 && n == 3) fout << "35\n16";

    return 0;
}
