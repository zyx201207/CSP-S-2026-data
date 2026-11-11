#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, a[N];
long long ans;
char c[N];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i] >> c[i];
  }
  int left = 1, right = n;
  for(; left < right; ){
    //cout << left << " " << right << '\n';
    if(a[left] == a[right]){
      if(c[left] != c[right]){
        ans += a[left];
      }
      left++;
      right--;
    }else if(a[left] < a[right]){
      if(c[left] != c[right]){
        ans += a[left];
      }
      a[right] -= a[left];
      left++;
    }else{
      if(c[left] != c[right]){
        ans += a[right];
      }
      a[left] -= a[right];
      right--;
    }
  }
  cout << ans;
  return 0;
}
