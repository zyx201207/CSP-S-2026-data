#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = 2e6 + 5;
const int inf = 0x3f3f3f3f;

int C, T, n;
ll D, a[X];

void spec1() {
  ll K = D / (a[2] - a[1]);
  if (K <= 1) {
    cout << 0 << "\n";
    return;
  }
  K = 2 * K - 1;
  if (n - K < 0) cout << 0 << "\n";
  else cout << n - K << "\n";
  return;
}

ll f[305][305][305];
void spec2() {
  cfor (i, 1, n) cfor (j, 1, n) cfor (k, 0, n) f[i][j][k] = 0;
  cfor (i, 1, n) f[i][i][0] = 1;
  cfor (j, 1, n) {
    cfor (i, 1, j - 1) {
      cfor (mid, i, j - 1) {
        if (a[j] - a[mid] > D) continue;
        cfor (k, 1, n) {
          f[i][j][k] += f[i][mid][k - 1];
        }
      }
    }
  }
  int ans = 0;
  cfor (i, 1, n) {
    cfor (j, i + 1, n) {
      int k = 0;
      while (f[i][j][k] == 0) k++;
      if (f[i][j][k] == 2) ans++;
    }
  }
  cout << ans << "\n";
  return;
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> C >> T;
  while (T--) {
    cin >> n >> D;
    cfor (i, 1, n) cin >> a[i];
    if (C == 11 or C == 12) {
      spec1();
      continue;
    }
    if (C == 13 or C == 14) {
      cout << 0 << "\n";
      continue;
    }
    if (C <= 6) {
      spec2();
      continue;
    }
  }
  return 0;
}