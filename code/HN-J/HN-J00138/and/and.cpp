#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, m, a[N], ans;
bool vis[N], vv[N];
vector<int> v[30];

int main() {
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j < 30; j++) {
      if (a[i] >> j & 1) {
        v[j].push_back(i);
      }
    }
    vis[i] = 1;
  }
  for (int j = 29; j >= 0; j--) {
    int cnt = 0;
    for (int i : v[j]) {
      cnt += vis[i];
    }
    if (cnt < m) continue ;
    for (int i : v[j]) {
      vv[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
      vis[i] &= vv[i];
    }
    ans |= 1 << j;
    for (int i : v[j]) {
      vv[i] = 0;
    }
  }
  cout << ans;
  return 0;
}
