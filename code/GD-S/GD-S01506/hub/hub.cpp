#include <bits/stdc++.h>
#define F(i, l, r) for (int i = (l); i <= (r); i ++)
#define G(i, r, l) for (int i = (r); i >= (l); i --)
#define MP make_pair
#define fi first
#define se second
#define pb push_back
using namespace std; 
typedef long long LL;

const int N = 2e6 + 7; 

template <typename T>
void Fmax(T &x, T y) { x = x > y ? x : y; }
template <typename T>
void Fmin(T &x, T y) { x = x < y ? x : y; }

LL read() {
  char c = getchar();
  LL x = 0, p = 0;
  while (c < '0' || c > '9')
    p ^= (c == '-'), c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return p ? -x : x;
}

vector<int> e[N];
int n, k, len[N], dp[N], f[N], lpy[N], d;

void dfs(int x, int pre) {
  len[x] = 0, dp[x] = 1;
  for (int i : e[x]) if (i != pre) {
    dfs(i, x), Fmax(len[x], len[i] + 1); 
    if (len[i] >= d) dp[x] += dp[i];
  }
}
void shx(int x, int pre, int dep) {
  if (len[x] == d) {
    f[x] = 1, lpy[x] = dep;
    return ;
  }
  f[x] = 0;
  int cnt = 0, zzj = n;
  for (int i : e[x]) if (i != pre) {
    shx(i, x, dep + 1);
    if (len[i] >= d)
      cnt ++, f[x] = f[i], lpy[x] = lpy[i];
    else if (dep + len[i] >= d)
      Fmin(zzj, dep + d - len[i] - 1);
  }
  if (cnt >= 2) lpy[x] = dep, f[x] = dp[x];
  else if (lpy[x] > zzj) f[x] += lpy[x] - zzj, lpy[x] = zzj;
}
int calc(int x, int c) {
  if (len[x] <= d) return 1;
  shx(x, c, 2);
  return f[x];
}
bool chk(int x) {
  d = x;
  F(c, 1, n) if (e[c].size() >= 2) {
    vector<int> buc;
    for (int i : e[c]) {
      dfs(i, c);
      if (len[i] >= x - 1) buc.push_back(i);
    }
    if (buc.size() >= 3) continue;
    if (!buc.size()) return true;
    if (buc.size() == 1) {
      if (dp[buc[0]] <= k || 1 + calc(buc[0], c) <= k) return true;
    } else {
      if (dp[buc[0]] + calc(buc[1], c) <= k) return true;
      if (dp[buc[1]] + calc(buc[0], c) <= k) return true;
    }
  }
  return false;
}

void solve() {
  n = read(), k = read();
  F(i, 1, n) e[i].clear();
  for (int i = 1, u, v; i < n; i ++) {
    u = read(), v = read();
    e[u].pb(v), e[v].pb(u);
  }
  if (k == n) return puts("0"), void();
  if (n == 2) return puts("1"), void();
  int l = 0, r = n - 1;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (chk(mid)) r = mid;
    else l = mid;
  }
  cout << r << '\n';
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  int c = read(), T = read();
  while (T --) solve();
  return 0;
}

