#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fi first
#define se second
using namespace std;

const int N = 500 + 5, M = 5e5 + 10;
const ll mod = 998244353;

void chkmin(int& x, int y){if(x > y) x = y;}
void chkmax(int& x, int y){if(x < y) x = y;}
void chkmin(ll& x, ll y){if(x > y) x = y;}
void chkmax(ll& x, ll y){if(x < y) x = y;}
void ADD(ll& x, ll y){x += y; (x >= mod) ? (x -= mod) : 0;}
void ADD(int& x, int y){x += y; (x >= mod) ? (x -= mod) : 0;}

int n, m, d, ww[N][M], qaq[M]; 
vector<int> vec[M]; 

ll dis[N][N]; 

void solve(){
  int ccc, Q; cin >> ccc >> n >> m >> d >> Q;
  for(int i = 1; i <= m; i++) cin >> qaq[i];
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) dis[i][j] = 1e18; 
  for(int i = 1; i <= n; i++){
    int xa; cin >> xa; 
    for(int j = 1; j <= xa; j++){
      int a; ll t; cin >> a >> t; ww[i][a] = t; 
      for(auto v : vec[a]) chkmin(dis[i][v], ww[i][a] + ww[v][a]), chkmin(dis[v][i], ww[i][a] + ww[v][a]);
      vec[a].pb(i);
    }
  }
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++) 
        chkmin(dis[i][j], dis[i][k] + dis[k][j]);
  // for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cerr << 
  while(Q--){
    int x, y; cin >> x >> y; ll ans = 1e18; 
    for(auto qx : vec[x]) for(auto qy : vec[y]) chkmin(ans, ww[qx][x] + ww[qy][y] + dis[qx][qy] + qaq[x] + qaq[y]);
    cout << ans << "\n"; 
  }  
}
void clr(){

}

signed main(){
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout); 
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T = 1; while(T--) solve(), clr();

  return 0;
}