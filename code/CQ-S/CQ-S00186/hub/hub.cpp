#include <bits/stdc++.h>
constexpr int N = 1e6 + 10;
int n, lim;
std::vector<int> to[N];
int dep[N], par[N], rp, rq;
void dfs1(int u) {
  dep[u] = dep[par[u]] + 1;
  for (int v : to[u])
    if (v != par[u])
      par[v] = u, dfs1(v);
}
int path[N], pn;
int vis[N], hei[N];
void dfs2(int u, int fa) {
  hei[u] = 0;
  for (int v : to[u])
    if (! vis[v] && v != fa)
      dfs2(v, u), hei[u] = std::max(hei[u], hei[v] + 1);
}
int pre[N], suf[N], pl[N], pr[N];
int mx1[20][N], mx2[20][N];
inline int query1(int l, int r) {
  int k = std::__lg(r - l + 1);
  return std::max(mx1[k][l], mx1[k][r - (1 << k) + 1]);
}
inline int query2(int l, int r) {
  int k = std::__lg(r - l + 1);
  return std::max(mx2[k][l], mx2[k][r - (1 << k) + 1]);
}
inline int calc1(int L, int R, int x) {
  if (L > R) return 0;
  int l = L, r = R, p = R + 1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (query1(L, mid) + mid >= x)
      p = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return R - p + 1;
}
inline int calc2(int L, int R, int x) {
  if (L > R) return 0;
  int l = L, r = R, p = L - 1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (query2(mid, R) - mid >= x)
      p = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return p - L + 1;
}
int cnt[N];
inline bool check(int i, int x) {
  return cnt[x] + calc1(1, pl[i] - 1, x) + calc2(pl[i] + 1, i, x) + calc1(i + 1, pr[i] - 1, x) + calc2(pr[i] + 1, pn, x)
         <= lim;
}
inline void solve(int tt) {
  scanf("%d%d", &n, &lim), lim -= 2;
  for (int i = 1; i <= n; i++)
    to[i].clear();
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    to[u].push_back(v);
    to[v].push_back(u);
  }
  dep[0] = -1;
  par[1] = 0, dfs1(1), rp = std::max_element(dep + 1, dep + n + 1) - dep;
  par[rp] = 0, dfs1(rp), rq = std::max_element(dep + 1, dep + n + 1) - dep;
  pn = 0;
  for (int u = rq; u; u = par[u])
    path[++pn] = u;
  std::fill(vis + 1, vis + n + 1, 0);
  for (int i = 1; i <= pn; i++)
    vis[path[i]] = 1;
  for (int i = 1; i <= pn; i++)
    dfs2(path[i], 0);
  for (int i = 1; i <= pn; i++)
    pre[i] = std::max(pre[i - 1], i - 1 + hei[path[i]]);
  suf[pn + 1] = 0;
  for (int i = pn; i >= 1; i--)
    suf[i] = std::max(suf[i + 1], pn - i + hei[path[i]]);
  for (int i = 1; i < pn; i++)
    pl[i] = 1 + pre[i] / 2, pr[i] = pn - suf[i + 1] / 2;
  for (int i = 1; i <= pn; i++)
    mx1[0][i] = hei[path[i]] - i, mx2[0][i] = hei[path[i]] + i;
  for (int i = 1; i < 20; i++)
    for (int l = 1, r = 1 << i; r <= pn; l++, r++) {
      mx1[i][l] = std::max(mx1[i - 1][l], mx1[i - 1][l + (1 << i - 1)]);
      mx2[i][l] = std::max(mx2[i - 1][l], mx2[i - 1][l + (1 << i - 1)]);
    }
  std::fill(cnt, cnt + n + 1, 0);
  for (int i = 1; i <= n; i++)
    if (! vis[i])
      cnt[hei[i]]++;
  for (int i = n - 1; i >= 0; i--)
    cnt[i] += cnt[i + 1];
  int ans = n - 1;
  for (int i = 1; i < pn; i++) {
    while (ans && check(i, ans - 1))
      ans--;
  }
  printf("%d\n", ans);
}
int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  int tn; scanf("%*d%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
    solve(tt);
  return 0;
}