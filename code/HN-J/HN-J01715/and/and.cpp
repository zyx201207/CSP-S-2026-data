#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = (1 << 21) - 1;

int n, m, a[N], po[25];

namespace subtask1{
  int ans;
  void dfs(int sum, int cnt, int ct){
    if(ct == m){
      ans = max(ans, sum);
      return;
    }
    if(cnt == n + 1) return;
    dfs(sum & a[cnt], cnt + 1, ct + 1);
    dfs(sum, cnt + 1, ct);
  }
  void Solve(){
    ans = 0;
    dfs(INF, 1, 0);
    cout << ans;
  }
};

namespace subtask2{
  void Solve1(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
      ans = max(ans, a[i]);
    }
    cout << ans;
  }
  void Solve2(){
    int ans = a[1];
    for(int i = 2; i <= n; i++){
      ans &= a[i];
    }
    cout << ans;
  }
  void Solve3(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
      for(int j = i + 1; j <= n; j++){
        ans = max(ans, a[i] & a[j]);
      }
    }
    cout << ans;
  }
};

namespace subtask3{
  void Solve(){
    sort(a + 1, a + n + 1, greater<int>());
    cout << a[m];
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  cin >> n >> m;
  po[0] = 1;
  for(int i = 1; i <= 21; i++){
    po[i] = po[i - 1] * 2;
  }
  bool f = 1;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    int pos = lower_bound(po, po + 22, a[i]) - po;
    f &= (po[pos] - 1 == a[i]);
  }
  if(n <= 20){
    subtask1::Solve();
  }else if(m == 1){
    subtask2::Solve1();
  }else if(m == n){
    subtask2::Solve2();
  }else if(m == 2 && n <= 2000){
    subtask2::Solve3();
  }else if(f){
    subtask3::Solve();
  }
  return 0;
}
