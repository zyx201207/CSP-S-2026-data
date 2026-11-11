#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fi first
#define se second
using namespace std;

const int N = 5e5 + 10, M = 2e5 + 10;
const ll mod = 998244353;

void chkmin(int& x, int y){if(x > y) x = y;}
void chkmax(int& x, int y){if(x < y) x = y;}
void chkmin(ll& x, ll y){if(x > y) x = y;}
void chkmax(ll& x, ll y){if(x < y) x = y;}
void ADD(ll& x, ll y){x += y; (x >= mod) ? (x -= mod) : 0;}
void ADD(int& x, int y){x += y; (x >= mod) ? (x -= mod) : 0;}

int n;
ll a[N], m;  

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1); 
  ll sum = 0, l = 1, ans = 0;
  for(int r = 1; r <= n; r++){
    sum += a[r];
    while(l <= r && 1ll * (r - l + 1) * a[r] - sum > m) sum -= a[l], l++;
    chkmax(ans, r - l + 1);  
  } cout << ans << "\n";
}
void clr(){

}

signed main(){
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout); 
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T = 1; while(T--) solve(), clr();

  return 0;
}