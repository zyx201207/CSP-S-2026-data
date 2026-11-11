#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2 * 1e5 + 5;
int n;

vector<int> v;
vector<char> vc;

int main() {
#ifndef LOCAL
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
#endif
  scanf("%d", &n);
  char prec, curc;
  for (int i = 1; i <= n; i++) {
    ll a;
    scanf("%lld %c", &a, &curc);

    if (prec == curc) {
      v[v.size() - 1] += a;
    } else
      v.push_back(a), vc.push_back(curc);
  }

  ll ans = 0;
  for (int i = 0; i < v.size() / 2; i++) {
    int j = v.size() - i - 1;
    if (vc[i] == vc[j]) {
      ans += abs(v[i] - v[j]);
    } else
      ans += max(v[i], v[j]);
  }

  printf("%lld", ans);
  return 0;
}