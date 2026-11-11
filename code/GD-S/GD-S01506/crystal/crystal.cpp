#include <bits/stdc++.h>
#define F(i, l, r) for (int i = (l); i <= (r); i ++)
#define G(i, r, l) for (int i = (r); i >= (l); i --)
#define MP make_pair
#define fi first
#define se second
#define pb push_back
using namespace std; 
typedef long long LL;

const int N = 5e5 + 7; 

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

LL n, a[N], pre[N], m, ans;

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  n = read(), m = read();
  F(i, 1, n) a[i] = read();
  sort(a + 1, a + n + 1);
  F(i, 1, n) pre[i] = pre[i - 1] + a[i]; 
  auto chk = [&](int l, int r) {
    return (r - l + 1) * a[r] - (pre[r] - pre[l - 1]) <= m; 
  }; 
  for (LL i = 1, j = 1; i <= n; i ++) {
    while (!chk(j, i)) j ++;
    Fmax(ans, i - j + 1);
  }
  cout << ans << '\n';
  return 0;
}

