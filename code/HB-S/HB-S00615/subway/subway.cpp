#include <bits/stdc++.h>
#define fori(na, st, ed) for (int na = st; na <= ed; na++)
#define forn(na, ed) fori(na, 1, ed)
#define fora(na, st, ed) for (int na = st; na >= ed; na--)
#define fors(na, st) fora(na, st, 1)
#define ffgetc getchar_unlocked
#define ffputc putchar_unlocked
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
namespace solve {
const int N = 5e5 + 5;
int c, n, m, d, q, w[N], dis[N][505];
vector<pair<int, int>> t[N];
struct mhash {
  int operator()(const pair<int, int>& x) const { return x.first ^ x.second; }
};
unordered_map<pair<int, int>, pair<int, int>, mhash> e;
unordered_map<pair<int, int>, bool, mhash> bk;
void solve() {
  scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
  forn(i, m) { scanf("%d", &w[i]); }
  forn(i, n) {
    int k, l = 0;
    scanf("%d", &k);
    forn(j, k) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (l) {
        e[{l, i}].second = x;
        e[{x, i}].first = l;
      }
      l = x;
      t[x].push_back({y, i});
    }
  }
  forn(i, q) {
    int x, y;
    scanf("%d%d", &x, &y);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    memset(dis, 0x3f, sizeof dis);
    bk.clear();
    for (auto z : t[x]) {
      pq.push({z.first, {x, z.second}});
      dis[x][z.second] = z.first;
    }
    while (!pq.empty()) {
      int u = pq.top().second.first, l = pq.top().second.second;
      pq.pop();
      // eprintf("%d %d %d\n", u, l, dis[u][l]);
      if (bk[{u, l}]) {
        continue;
      }
      bk[{u, l}] = 1;
      int v = e[{u, l}].first;
      if (v != 0) {
        for (auto z : t[v]) {
          int tmp =
              dis[u][l] +
              (l != z.second
                   ? (find_if(t[v].begin(), t[v].end(),
                              [&](pair<int, int> x) { return x.second == l; })
                          ->first +
                      z.first)
                   : 0);
          if (dis[v][z.second] > tmp) {
            dis[v][z.second] = tmp;
            pq.push({tmp, {v, z.second}});
            // eprintf("%d %d %d\n", v, z.second, tmp);
          }
        }
      }
      v = e[{u, l}].second;
      if (v != 0) {
        for (auto z : t[v]) {
          int tmp =
              dis[u][l] +
              (l != z.second
                   ? (find_if(t[v].begin(), t[v].end(),
                              [&](pair<int, int> x) { return x.second == l; })
                          ->first +
                      z.first)
                   : 0);
          if (dis[v][z.second] > tmp) {
            dis[v][z.second] = tmp;
            pq.push({tmp, {v, z.second}});
            // eprintf("%d %d %d\n", v, z.second, tmp);
          }
        }
      }
    }
    // forn(j, m) { eprintf("%d ", dis[i]); }
    // eprintf("\n");
    int ans = INT_MAX;
    for (auto z : t[y]) {
      ans = min(ans, dis[y][z.second] + z.first);
    }
    printf("%d\n", ans + w[x] + w[y]);
  }
}
} // namespace solve
signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  int T = 1;
  while (T-- > 0) {
    solve::solve();
  }
}
// 第二题（subway）中的样例解释请忽略公式中的变量部分，以文字叙述部分与公式中的数值部分为准。
// 绗簩棰橈紙subway锛変腑鐨勬牱渚嬭В閲婅蹇界暐鍏紡涓殑鍙橀噺閮ㄥ垎锛屼互鏂囧瓧鍙欒堪閮ㄥ垎涓庡叕寮忎腑鐨勬暟鍊奸儴鍒嗕负鍑嗐€�