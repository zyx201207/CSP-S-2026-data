#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define pii pair <int, int>
#define chkmx(a, b) (a = max(a, (b)))
#define chkmn(a, b) (a = min(a, (b)))
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N];
int cul(int mid){
  int res = 0;
  for (int i = 1; i <= mid; i ++) res += a[i];
  int ret = 4e18;
  for (int i = mid; i <= n; i ++){
    chkmn(ret, mid * a[i] - res);
    res -= a[i - mid + 1];
    res += a[i + 1];
  }
  return ret;
}
void solve(){
  cin >> n >> m;
  for (int i = 1; i <= n; i ++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int l = 1, r = n, ans = -1;
  while (l <= r){
    int mid = (l + r) >> 1;
    if (cul(mid) <= m) ans = mid, l = mid + 1;
    else r = mid - 1;
  }
  cout << ans << endl;
}
signed main(){
  cin.tie(0)->sync_with_stdio(0);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  int _ = 1; //cin >> _;
  while (_ --) solve();
  return 0;
}