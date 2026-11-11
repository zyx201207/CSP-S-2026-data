#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, m, a[N];

namespace subtask1{
  int ans[N];
  void Solve(){
    for(int i = 1; i <= n; i++){
      ans[a[i]] = i;
    }
    for(int i = 1; i <= m; i++){
      cout << ans[i] << " ";
    }
  }
}

namespace subtask2{
  int vis[N], ans[N];
  stack<int> st;
  void Solve(){
    for(int i = 1; i <= n; i++){
      for(int j = i; j <= n; j++){
        if(!vis[a[j]]){
          st.push(a[j]);
          vis[a[j]] = 1;
        }else{
          while(st.size()){
            int u = st.top();
            st.pop();
            if(u == a[j]) break;
            vis[u] = 0;
          }
          st.push(a[j]);
        }
      }
      for(int i = 1; i <= m; i++) ans[i] += vis[i];
      fill(vis + 1, vis + m + 1, 0);
    }
    for(int i = 1; i <= m; i++){
      cout << ans[i] << " ";
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
  cin >> n >> m;
  bool f = 1;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    f &= (a[i - 1] <= a[i]);
  }
  if(f){
    subtask1::Solve();
  }else{
    subtask2::Solve();
  }
  return 0;
}
