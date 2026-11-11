#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, M = 30;
using ll = long long;

ll n, m, a[N], vis[N];

int main(){
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  ll ans = 0;
  for(int j = M; j >= 0; j--){
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
      if((a[i] >> j) % 2 == 1 && vis[i] == 0){
        cnt++;
      }
    }
    if(cnt >= m){
      ans += (1 << j);
      for(int i = 1; i <= n; i++){
        if((a[i] >> j) % 2 == 0){
          vis[i] = 1;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
