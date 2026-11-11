#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define U(i,a,b) for(int i = (a); i < (b); i++)
#define drep(i,a,b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define ld lower_bound
#define pii pair<ll,ll>
#define vi vector<ll>
#define fi first
#define se second
#define fv inline void
#define fn inline static
#define mem(s,x) memset(s, x, sizeof(s))
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using i32 = ll; using i64 = ll; using u32 = unsigned int; using u64 = unsigned long long;
const i32 mod = 998244353, inf = 1e18;
fv inc(i32 &x, i32 y) { x = (x + y >= mod ? x + y - mod : x + y); }
fv dec(i32 &x, i32 y) { x = (x - y < 0 ? x - y + mod : x - y); }
fn i32 madd(i32 x, i32 y) { return (x + y >= mod ? x + y - mod : x + y); }
fn i32 msub(i32 x, i32 y) { return (x - y < 0 ? x - y + mod : x - y); }
const i32 N = 2e6 + 5;
i32 n, d, numid, a[N], L[N], R[N], visL[N], visR[N], f[N], g[N];
vi GL[N], GR[N];
fv sol() {
  numid++;
  cin >> n >> d;
  rep (i, 1, n) cin >> a[i];
  // if (numid == 29) {
  //   cerr << 0 << " " << 1 << "\n";
  //   cerr << n << " " << d << "\n";
  //   rep (i, 1, n) cerr << a[i] << " ";
  //   cerr << "\n";
  //   exit(0);
  // }
  rep (i, 0, n + 1) f[i] = g[i] = 0;
  L[n + 1] = n + 1;
  rep (i, 1, n) {
    R[i] = R[i - 1];
    while (R[i] < n && a[R[i] + 1] - a[i] <= d) R[i]++;
  }
  drep (i, n, 1) {
    L[i] = L[i + 1];
    while (L[i] > 1 && a[i] - a[L[i] - 1] <= d) L[i]--;
  }
  rep (i, 1, n) GL[i].clear(), GR[i].clear();
  rep (i, 1, n) GL[R[i]].pb(i), GR[L[i]].pb(i);
  // rep (i, 1, n) cerr << a[i] << " ";
  // cerr << "\n";
  // rep (i, 1, n) cerr << L[i] << " ";
  // cerr << "\n";
  // rep (i, 1, n) cerr << R[i] << " ";
  // cerr << "\n";
  rep (i, 1, n) {
    if (L[R[i]] == i) visR[i] = 0;
    else if (L[R[i]] == i - 1) visR[i] = 1;
    else visR[i] = 2;
  }
  rep (i, 1, n) {
    if (R[L[i]] == i) visL[i] = 0;
    else if (R[L[i]] == i + 1) visL[i] = 1;
    else visL[i] = 2;
  }
  rep (i, 1, n) f[i] = g[i] = 1;
  rep (i, 1, n) if (visR[R[i]] == 0) f[R[i]] += f[i];
  drep (i, n, 1) if (visL[L[i]] == 0) g[L[i]] += g[i];
  i32 ans = 0;
  rep (i, 1, n) {
    if (visR[i] == 1 && R[i] != i) {
      i32 r = R[i], u = L[r], lnum = 0, rnum = 0;
      for (i32 pre : GL[i]) {
        if (L[u] == pre) lnum += f[pre];
        else lnum += 1;
      }
      rnum = g[r];
      ans += lnum * rnum;
      // cerr << i << " : " << lnum << " : " << rnum << "\n";
    }
  }
  rep (i, 1, n - 1) {
    i32 l = L[i];
    if (R[l + 1] > i) {
      for (i32 pre : GL[l + 1]) {
        if (pre >= l) continue ;
        // cerr << i << " - " << pre << " - " << f[pre] << "\n";
        if (L[l] == pre) ans += f[pre];
        else ans++;
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  IOS;
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  i32 c, T; cin >> c >> T;
  while (T--) sol();  
}