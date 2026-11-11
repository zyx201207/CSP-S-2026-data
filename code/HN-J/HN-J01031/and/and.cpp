#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 2e5 + 10;
int n, m, a[M], vis[M], mp[M], ans;
void dfs(int x, int sum){
  if(x == m + 1){
    ans = max(ans, sum);
    return;
  }
  for(int i = 1;i <= n;i++){
    if(!vis[i]){
      vis[i] = 1;
      dfs(x + 1, (sum != -1 ? sum & a[i] : a[i]));
      vis[i] = 0;
    }
  }
}
void init(){
  mp[0] = 1;
  for(int i = 1;i < 31;i++){
    mp[i] = mp[i - 1] * 2;
  }
}
bool check1(){
  for(int i = 1;i <= n;i++){
    bool flag = 0;
    for(int j = 0;j < 31;j++){
      if(a[i] == mp[j] - 1){
        flag = 1;
        break;
      }
    }
    if(!flag) return 0;
  }
  return 1;
}
bool check2(){
  bool flag = 0;
  for(int i = 0;i < 31;i++){
    if(n == mp[i]){
      flag = 1;
      break;
    }
  }
  if(!flag) return 0;
  for(int i = 1;i <= n;i++){
    if(a[i] != i - 1){
      return 0;
    }
  }
  return 1;
}
bool cmp(int x, int y){
  return x > y;
}
void solve1(){
  sort(a + 1, a + n + 1, cmp);
  int sum = a[1];
  for(int i = 2;i <= m;i++){
    sum &= a[i];
  }
  ans = sum;
}
void solve2(){
  solve1();
}
int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  cin >> n >> m;
  init();
  for(int i = 1;i <= n;i++){
    cin >> a[i];
  }
  if(n <= 2000){
    dfs(1, -1);
  }
  else if(check1()){
    sort(a + 1, a + n + 1);
    ans = a[m];
  }
  else if(check2()){
    solve1();
  }
  else{
    solve2();
  }
  cout << ans;
  return 0;
}
