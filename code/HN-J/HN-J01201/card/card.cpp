#include <bits/stdc++.h>
using namespace std;

const int N1 = 2e5 + 5, M1 = 1e5 + 5;
using ll = long long;

ll n, m, a[N1], vis[N1], cnt[M1];

namespace sa{
  ll p[M1];
  void solve(){
    for(int i = 0; i <= m; i++){
      p[i] = 0;
    }
    for(int i = 1; i <= n; i++){
      p[a[i]] = i;
    }
    for(int i = 1; i <= m; i++){
      cout << p[i] << ' ';
    }
    return;
  }
}

namespace sn{
  ll p[N1], c[N1];
  void solve(){
    for(int i = 1; i <= n; i++){
      p[i] = i;
    }
    for(int i = 1; i <= n; i++){
      for(int j = i - 1; j >= 1; j--){
        if(a[i] == a[j]){
          p[i] = j;
          break;
        }
      }
    }
    for(int o = 1; o <= n; o++){
      for(int i = o; i <= n; i++){
        if(p[i] >= o && p[i] != i && vis[p[i]] != o){
          for(int j = p[i]; j < i; j++){
            vis[j] = o;
          }
        }
      }
      /*
      cout << o << '\n';
      for(int i = 1; i <= n; i++){
        cout << c[i] << ' ';
      }
      cout << '\n';
      */
      for(int i = o; i <= n; i++){
        if(vis[i] != o){
          cnt[a[i]]++;
        }
      }
    }
    for(int i = 1; i <= m; i++){
      cout << cnt[i] << ' ';
    }
  }
}

int main(){
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  ll e = 1;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    if(i > 1 && a[i] < a[i - 1]){
      e = 0;
    }
  }
  if(e){
    sa::solve();
  }else{
    sn::solve();
  }
  return 0;
}
