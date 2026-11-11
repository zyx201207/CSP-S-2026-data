#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fi first
#define se second
using namespace std;

const int N = 2e6 + 10, M = 5e5 + 10;
const ll mod = 998244353;

void chkmin(int& x, int y){if(x > y) x = y;}
void chkmax(int& x, int y){if(x < y) x = y;}
void chkmin(ll& x, ll y){if(x > y) x = y;}
void chkmax(ll& x, ll y){if(x < y) x = y;}
void ADD(ll& x, ll y){x += y; (x >= mod) ? (x -= mod) : 0;}
void ADD(int& x, int y){x += y; (x >= mod) ? (x -= mod) : 0;}

int n, lst[N], nxt[N], s[N]; 
ll a[N], f[N][3], d, s2[N]; 

bool check(int l, int r){
  int p = l; vector<int> vec, vec2; 
  while(p < r && p != nxt[p]) vec.pb(p), p = nxt[p]; 
  if(p < r) return false;
  vec.pb(r); p = r;
  while(p > l && p != lst[p]) vec2.pb(p), p = lst[p];
  if(p > l) return false;
  vec2.pb(l); reverse(vec2.begin(), vec2.end()); 
  int ans = 0;
  assert(vec.size() == vec2.size()); 
  for(int i = 0; i < vec.size(); i++){
    int dif = vec[i] - vec2[i];
    if(dif == 1) ans++; 
    else if(dif) return 0;
  } return (ans == 1); 
}

void solve(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int j = 1; 
  for(int i = 1; i <= n; i++){
    while(a[i] - a[j] > d) j++; 
    lst[i] = j; 
  } j = n;
  for(int i = n; i; i--){
    while(a[j] - a[i] > d) j--; 
    nxt[i] = j; 
  } ll ans = 0, rans = 0; 
  // cerr << check(1, 9) << "\n";
  // for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) if(check(i, j)) rans++;
  // cout << rans << "\n";
  // for(int i = 1; i <= n; i++) cerr << lst[i] << " " << nxt[i] << "\n";
  for(int i = 1; i <= n; i++){
    f[i][0] = f[i][1] = f[i][2] = 0;
    if(lst[i] < i && nxt[lst[i]] == i) f[i][0] = f[lst[i]][0], f[i][2] = f[lst[i]][2];
    // if(lst[i] + 1 < i && nxt[lst[i] + 1] == i + 1) f[i][1] += f[lst[i]][1];
    if(lst[i] + 1 < i && nxt[lst[i] + 1] == i) f[i][2] += f[lst[i]][1]; 
    if(lst[i] + 1 < i && nxt[lst[i] + 1] > i) ans += f[lst[i]][1];
    if(lst[i] + 1 < i && nxt[lst[i]] > i) ans += f[lst[i]][2];
    if(lst[i] < i && nxt[lst[i]] == i + 1) f[i][1] += f[lst[i]][0]; 
    if(lst[i] < i) f[i][1] += s[i + 1], ans += f[i][2], f[i][0] += s[i];
    s[nxt[i]]++; 
  } cout << ans << "\n"; 
}
void clr(){
  for(int i = 1; i <= n; i++) s[i] = 0;
}

signed main(){
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout); 
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T = 1, c; cin >> c >> T; while(T--) solve(), clr();

  return 0;
}
/*
0 1
10 21
0 7 14 21 28 35 42 49 56 63
*/
