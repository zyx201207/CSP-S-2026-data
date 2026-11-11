#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IL inline
const int N = 2e6 + 5;
ll d, a[N];
int n, pre[N], nxt[N];
bool bad[N];
bool To(int i, int j) {
  if (i < 1 || i > n || j < 1 || j > n)
    return 0;
  return a[j] - a[i] <= d;
}
int cpre[N], cnxt[N];
ll cpre_nxtis[N];
vector<int> nxtis[N];
void ___() {
  cin >> n >> d;
  fill(cpre + 1, cpre + n + 1, 0);
  fill(cnxt + 1, cnxt + n + 1, 0);
  fill(cpre_nxtis + 1, cpre_nxtis + n + 1, 0);
  for (int i = 1; i <= n; ++i)
    nxtis[i].clear();
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  // for (int i = 1; i <= n; ++i)
  //   cout << i << ' ' << a[i] + 1000000000000000000 << '\n';
  int now = n;
  for (int i = n; i >= 1; --i) {
    while (a[now] > a[i] + d) --now;
    nxt[i] = now;
  }
  now = 1;
  for (int i = 1; i <= n; ++i) {
    while (a[now] < a[i] - d) ++now;
    pre[i] = now;
  }
  for (int i = 1; i <= n; ++i) {
    if (To(i - 1, nxt[i])) bad[i] = 1;
    else bad[i] = 0;
  }
  for (int i = 1; i <= n; ++i)
    nxtis[nxt[i]].push_back(i);
  for (int i = 1; i <= n; ++i) {
    cpre[i] = 1;
    for (int j : nxtis[i]) {
      if (bad[j] || j == i) continue;
      cpre[i] += cpre[j];
    }
  }
  for (int i = n; i >= 1; --i) {
    cnxt[i] = nxt[i] - i + 1;
    if (nxt[i] == i) continue;
    int t = nxt[nxt[i] - 1];
    if (t == nxt[nxt[i]]) continue;
    cnxt[i] += cnxt[nxt[i]];
    cnxt[i] -= nxt[nxt[i]] - nxt[i] + 1;
    cnxt[i] += nxt[nxt[i]] - t;
  }
  for (int i = 1; i <= n; ++i) {
    if (nxt[i - 1] == nxt[i]) {
      cnxt[i] = 0;
    } else {
      cnxt[i] -= nxt[i - 1] - i + 1;
    }
  } 
  for (int i = 1; i <= n; ++i) {
    if (nxt[i] == i + 1) continue;
    cpre_nxtis[nxt[i]] += cpre[i];
  }
  // cout << cpre_nxtis[8] << ' ' << cpre[7] << '\n';
  ll ans = 0;
  for (int i = 2; i <= n; ++i) {
    int l = i + 1, r = nxt[i];
    int mn = 1e9, mx = -1e9;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid] > a[i - 1] + d) r = mid - 1;
      else mx = mid, l = mid + 1;
    }
    l = i + 1, r = nxt[i];
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (i > 1 && a[mid] <= d + a[i - 2]) l = mid + 1;
      else mn = mid, r = mid - 1;
    }
    if (mn <= mx) {
      ans += cpre_nxtis[i] * (mx - mn + 1);
      // cout << "last: " << i << ' ' << mn << ' ' << mx << ' ' << cpre_nxtis[i] << '\n';
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!bad[i] || To(i - 2, nxt[i])) continue;
    ans += 1LL * cpre_nxtis[i] * cnxt[nxt[i]];
    // cout << "mid: " << i << ' ' << nxt[i] << ' ' << cpre_nxtis[i] << ' ' << cnxt[nxt[i]] - 1 << '\n';
  }
  cout << ans << '\n';
}
int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  // freopen("migrate3.in", "r", stdin);
  // freopen("in.x", "r", stdin);
  ios::sync_with_stdio(0); cin.tie(0);
  int cid, _; cin >> cid >> _;
  while (_--) ___();
  return 0;
}