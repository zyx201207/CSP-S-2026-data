#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define pii pair <int, int>
#define chkmx(a, b) (a = max(a, (b)))
#define chkmn(a, b) (a = min(a, (b)))
using namespace std;
const int N = 2e6 + 5;
int n, d, a[N], suf[N], pre[N], vis[N], sz[N], ansl[N], ansr[N];
vector <pii> edge[N];
void dfs(int p){
  vis[p] = 1, sz[p] = 1;
  for (auto [to, w] : edge[p]) if (!vis[to]) {
    dfs(to);
    if (w) sz[p] += sz[to];
    else sz[p] += 1;
  }
}
void solve(){
  cin >> n >> d;
  for (int i = 1; i <= n; i ++) cin >> a[i];
  for (int i = 1, j = 1; i <= n; i ++){
    while (j <= n && a[j] - a[i] <= d) j ++;
    suf[i] = j - 1;
    // cerr << suf[i] << " \n"[i == n];
  }
  for (int i = 1, j = 1; i <= n; i ++){
    while (a[i] - a[j] > d) j ++;
    pre[i] = j;
    // cerr << pre[i] << " \n"[i == n];
  }
  for (int i = 1; i <= n; i ++) edge[i].clear(), vis[i] = 0;
  for (int i = 1; i <= n; i ++){
    if (suf[pre[i]] == i) edge[pre[i]].pb(i, 1);
    else edge[pre[i]].pb(i, 0);
  }
  for (int i = 1; i <= n; i ++) if (!vis[i]) dfs(i);
  // for (int i = 1; i <= n; i ++) ansr[i] = sz[i];
  for (int i = 1; i < n; i ++){
    ansr[i] = 0;
    for (auto [to, w] : edge[i]) ansr[i] ++;
    if (suf[i] == suf[i + 1] && pre[suf[i]] == i) ansr[i] += sz[suf[i]] - 1;
  }

  for (int i = 1; i <= n; i ++) edge[i].clear(), vis[i] = 0;
  for (int i = 1; i <= n; i ++){
    if (pre[suf[i]] == i) edge[suf[i]].pb(i, 1);
    else edge[suf[i]].pb(i, 0);
  }
  for (int i = n; i >= 1; i --) if (!vis[i]) dfs(i);
  // for (int i = 1; i <= n; i ++) ansl[i] = sz[i];
  for (int i = 1; i < n; i ++){
    ansl[i] = 0;
    for (auto [to, w] : edge[i + 1])  ansl[i] ++;
    if (pre[i] == pre[i + 1] && suf[pre[i]] == i + 1) ansl[i] += sz[pre[i]] - 1;
  }
  // for (int i = 1; i < n; i ++) cerr << ansl[i] << ' '; cerr << endl;
  // for (int i = 1; i < n; i ++) cerr << ansr[i] << ' '; cerr << endl;

  int ans = 0;
  for (int mid = 1; mid + 1 <= n; mid ++){
    if (suf[mid] > mid + 1 && pre[mid + 1] < mid)
      ans += (ansr[mid]) * (ansl[mid]);
  }
  cout << ans << '\n';
}
signed main(){
  cin.tie(0)->sync_with_stdio(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  int _ = 1; cin >> _ >> _;
  while (_ --) solve();
  return 0;
}