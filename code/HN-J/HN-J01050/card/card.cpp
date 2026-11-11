#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

int n, m, a[MAXN], stk[MAXN], top, pos[MAXN], ans[MAXN];
bool del[MAXN];

int main() {
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  bool flag = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    flag &= a[i] >= a[i - 1];
  }
  if (flag) {
    for (int i = 2; i <= n; i++) {
      if (a[i] != a[i - 1]) ans[a[i - 1]] = i - 1;
    }
    ans[a[n]] = n;
    for (int i = 1; i <= m; cout << ans[i++] << ' ');
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    top = 0;
    fill(pos + 1, pos + m + 1, 0);
    fill(del + 1, del + n + 1, 0);
    for (int j = i; j <= n; j++) {
      if (pos[a[j]] && !del[pos[a[j]]]) for (; top && stk[top] >= pos[a[j]]; del[stk[top--]] = 1);
      stk[++top] = pos[a[j]] = j;
    }
    for (int j = 1; j <= top; ans[a[stk[j++]]]++);
  }
  for (int i = 1; i <= m; cout << ans[i++] << ' ');
  return 0;
}
