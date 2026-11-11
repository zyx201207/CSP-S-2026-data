#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 2e5 + 10;
int n, a[M], maxx;
char c[M];
ll ans;
void solve1(){
  string s;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= a[i];j++){
      s += c[i];
    }
  }
  for(int i = 0, j = s.size() - 1;i <= j;i++, j--){
    if(s[i] != s[j]){
      ans++;
    }
  }
}
void solve2(){
  for(int i = 1, j = n;i <= j;){
    if(a[i] == a[j] && c[i] == c[j]){
      i++, j--;
    }
    else if(c[i] != c[j] && a[i] == a[j]){
      ans += a[j];
      i++, j--;
    }
    else if(c[i] == c[j] && a[i] != a[j]){
      if(j - i > 1) ans += max(a[i], a[j]);
      i++, j--;
    }
    else{
      ans += max(a[i], a[j]);
      if(a[i] < a[j]){
        ll res = a[j];
        while(res && i < j){
          ll k = min(1ll * a[i], res);
          res -= k;
          a[i] -= k;
          i++;
        }
        j--;
      }
      else{
        ll res = a[i];
        while(res && i < j){
          ///cout << j << ' ';
          ll k = min(1ll * a[j], res);
          res -= k;
          a[j] -= k;
          j--;
        }
        i++;
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> a[i] >> c[i];
    maxx = max(maxx, a[i]);
  }
  if(maxx <= 500){
    solve1();
  }
  else{
    solve2();
  }
  ///aabaaa
  cout << ans;
  return 0;
}
/**
aaaaa bbb c
3
4 a
3 b
1 c
**/
