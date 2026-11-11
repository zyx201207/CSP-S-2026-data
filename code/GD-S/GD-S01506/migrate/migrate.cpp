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

LL d, a[N];
int n, nxt[N], dp[N][2];

void solve() {
  n = read(), d = read();
  F(i, 1, n) a[i] = read(); 
  for (int i = n, j = n; i >= 1; i --) {
    while (a[j] - a[i] > d) j --;
    nxt[i] = j;
  }
  G(i, n, 1) {
    if (nxt[nxt[i]] == nxt[max(i, nxt[i] - 2)]) {
      dp[i][0] = dp[i][1] = 0;
      continue;
    }
    dp[i][0] = nxt[nxt[i] - 1] - nxt[max(nxt[i] - 2, i)];
    dp[i][1] = nxt[nxt[i]] - nxt[nxt[i] - 1];
    if (!dp[i][1]) dp[i][0] += dp[nxt[i]][1];
    else {
      dp[i][0] += dp[nxt[i]][0], dp[i][1] += dp[nxt[i]][1];
      if (nxt[nxt[i] - 1] == nxt[nxt[i]] - 1) {
        if (nxt[nxt[nxt[i]] - 1] == nxt[nxt[nxt[i]]]) dp[i][0] -= dp[nxt[i]][0];
        else dp[i][0] -= nxt[nxt[nxt[i]] - 1] - nxt[max(nxt[nxt[i]] - 2, nxt[i])];
      }
    }
  }
  LL ans = 0;
  F(i, 1, n) ans += dp[i][0];
  cout << ans << '\n'; 
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  int c = read(), T = read();
  while (T --) solve();
  return 0;
}

