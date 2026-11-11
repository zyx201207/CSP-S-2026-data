#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m;
long long a[N];
int t[32];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
  cin >> n >>m;
  long long maxn = 0;
  long long tt;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    if(i == 1)tt = a[i];
    else tt &= a[i];
    maxn = max(maxn,a[i]);
    for(int j = 1;a[i] >= 1;j ++){
        if(a[i] % 2==1)t[j] ++;
        a[i] >>= 1;
    }
  }
  if(m == 1)return cout <<maxn,0;
  if(m == n)return cout <<tt,0;
  int ans =0;
  int tmp = 536870912;
  int y = 0;
  for(int i = 30; i >= 1; -- i){
    if(t[i] >= m and y < m) ans += tmp,y ++;
    tmp /= 2;
  }
  cout <<ans;
  return 0;
}
