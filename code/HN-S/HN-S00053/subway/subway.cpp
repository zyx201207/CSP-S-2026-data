#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

ifstream fin("subway.in");
ofstream fout("subway.out");

const LL kMaxN = 501, kMaxM = 5e5 + 1, kInf = 1e18;

vector<Pii> e[kMaxM];
LL w[kMaxM], l[kMaxN][kMaxN], n, m, d, q, tc;

int main() {
  fin >> tc >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    fin >> w[i];
  }
  fill(l[1], l[n + 1], kInf);
  for (int i = 1, k, x, y; i <= n; i++) {
    l[i][i] = 0;
    for (fin >> k; k--;) {
      fin >> x >> y;
      e[x].emplace_back(i, y);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < e[i].size(); j++) {
      for (int k = j + 1; k < e[i].size(); k++) {
        auto &x = e[i][j], &y = e[i][k];
        l[x.first][y.first] = l[y.first][x.first] = min(l[x.first][y.first], 0LL + x.second + y.second);
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        l[j][i] = l[i][j] = min(l[i][j], l[i][k] + l[k][j]);
      }
    }
  }
  for (int x, y; q--; ) {
    fin >> x >> y;
    LL ans = kInf;
    for (Pii i : e[x]) {
      for (Pii j : e[y]) {
        ans = min(ans, i.second + j.second + l[i.first][j.first]);
      }
    }
    fout << ans + w[x] + w[y] << '\n';
  }
  return 0;    
}