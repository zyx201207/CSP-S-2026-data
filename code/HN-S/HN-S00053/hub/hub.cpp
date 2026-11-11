#include <bits/stdc++.h>

using namespace std;

ifstream fin("hub.in");
ofstream fout("hub.out");

const int kMaxN = 1e6 + 1;

struct {
  vector<int> e;
  int l, r, c, d;
} v[kMaxN];
int a[kMaxN], tc, t, n, m, k, ans;

void B(int f, int x) {
  a[++m] = x, v[x].l = m;
  for (int i : v[x].e) {
    if (i != f) {
      B(x, i);
    }
  }
  v[x].r = m;
}

void T(int o) {
  vector<int> l[2];
  int c[2] = {}, len = 0;
  for (int i = 1; i <= n; i++) {
    v[i].d = 0, c[v[i].c]++;
    for (int j : v[i].e) {
      v[i].d += v[j].c == v[i].c;
    }
    if (v[i].d == 1) {
      l[v[i].c].emplace_back(i);
    }
  }
  for (; max(c[0], o) + max(c[1], o) > k; len++) {
    vector<int> nl[2];
    for (int i = 0; i <= 1; i++) {
      for (int x : l[i]) {
        c[i]--;
        for (int y : v[x].e) {
          if (v[y].c == v[x].c && --v[y].d == 1) {
            nl[i].emplace_back(y);
          }
        }
      }
    }
    l[0] = nl[0], l[1] = nl[1];
  }
  ans = min(ans, len);
}

int main() {
  for (fin >> tc >> t; t--; ) {
    fin >> n >> k;
    fill(v + 1, v + 1 + n, v[0]);
    for (int i = 1, x, y; i < n; i++) {
      fin >> x >> y;
      v[x].e.emplace_back(y), v[y].e.emplace_back(x);
    }
    m = 0, ans = n;
    B(0, 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        v[a[j]].c = v[a[j]].l >= v[a[i]].l && v[a[j]].l <= v[a[i]].r;
      }
      T(i > 1);
    }
    fout << ans << '\n';
  }
  return 0;    
}