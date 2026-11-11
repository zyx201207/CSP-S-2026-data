#include <bits/stdc++.h>

using namespace std;
using LL = long long;

ifstream fin("crystal.in");
ofstream fout("crystal.out");

const int kMaxN = 5e5 + 1;

LL a[kMaxN], s[kMaxN], n, m, ans;

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1, j = 0; i <= n; i++) {
    for (; (i - j) * a[i] - s[i] + s[j] > m; j++) {
    }
    ans = max(ans, 0LL + i - j);
  }
  fout << ans;
  return 0;    
}