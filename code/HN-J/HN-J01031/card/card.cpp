#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 5e5 + 10, N = 3e5 + 10;
int n, m, a[M], vis[N], mp[N], s[M], top;
void solve1(){
  for(int i = 1;i <= n;i++){
    for(int j = i;j <= n;j++){
      if(mp[a[j]]){
        while(s[top] != a[j]){
          mp[s[top]] = 0;
          top--;
        }
      }
      else{
        mp[a[j]] = 1;
        s[++top] = a[j];
      }
    }
    while(top != 0){
      mp[s[top]] = 0;
      vis[s[top]]++;
      top--;
    }
  }
  for(int i = 1;i <= m;i++){
    cout << vis[i] << ' ';
  }
}
int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1;i <= n;i++){
    cin >> a[i];
  }
  if(n <= 5000){
    solve1();
  }
  else{
    solve1();
  }
  return 0;
}
