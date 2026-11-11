#include <bits/stdc++.h>

constexpr int N = 5e5 + 10, M = 3e5 + 10;
int a[N], lst[M], nxt[N], buc[N], cnt[M];
std::vector<int> G[N];

void dfs(int u) {
  for (int v : G[u]) {
    dfs(v);
    buc[u] += buc[v];
  }
}

int main() {
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
  
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  int n, m;
  std::cin >> n >> m;
  
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    lst[a[i]] = i;
  }
  
  for (int i = 1; i < n; i++) G[lst[a[i + 1]]].emplace_back(i);
  for (int i = 1; i <= n; i++) buc[lst[a[i]]]++;
  
  dfs(n);
  
  for (int i = 1; i <= n; i++) cnt[a[i]] += buc[i];
  for (int i = 1; i <= m; i++) std::cout << cnt[i] << " \n"[i == m];
}
