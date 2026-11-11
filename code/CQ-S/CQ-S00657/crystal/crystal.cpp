#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define U(i,a,b) for(int i = (a); i < (b); i++)
#define drep(i,a,b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define ld lower_bound
#define pii pair<int,int>
#define vi vector<int>
#define fi first
#define se second
#define fv inline void
#define fn inline static
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using i32 = ll; using i64 = ll; using u32 = unsigned int; using u64 = unsigned long long;
const i32 mod = 998244353;
fv inc(i32 &x, i32 y) { x = (x + y >= mod ? x + y - mod : x + y); }
fv dec(i32 &x, i32 y) { x = (x - y < 0 ? x - y + mod : x - y); }
fn i32 madd(i32 x, i32 y) { return (x + y >= mod ? x + y - mod : x + y); }
fn i32 msub(i32 x, i32 y) { return (x - y < 0 ? x - y + mod : x - y); }
const i32 N = 5e5 + 5;
i32 n, m, sum, a[N];
int main() {
  IOS;
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin >> n >> m;
  rep (i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  i32 p = 1, ans = 0, sum = 0;
  rep (i, 1, n) {
    while (p <= i && sum > m) sum -= a[i] - a[p], p++;
    ans = max<i32>(ans, i - p + 1);
    sum += (i - p + 1) * (a[i + 1] - a[i]);
  }
  cout << ans << "\n";
}