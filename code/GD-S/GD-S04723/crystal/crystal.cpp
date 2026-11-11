#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = 5e5 + 5;
const int inf = 0x3f3f3f3f;

int n, ans;
ll m;
ll a[X], sum[X];

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  cfor (i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  cfor (i, 1, n) sum[i] = sum[i - 1] + a[i];
  int l = 1;
  cfor (r, 1, n) {
    while (a[r] * (r - l + 1) - (sum[r] - sum[l - 1]) > m) l++;
    ans = max(ans, r - l + 1);
  }
  cout << ans;
  return 0;
}