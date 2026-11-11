#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=500'010;
int n, m, ans, a[N];

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(0);
  cin>> n>> m;
  for(int i=1; i<=n; i++) cin>> a[i];
  sort(a+1, a+n+1);
  for(int i=1, j=1, s=0; i<=n; i++) {
    s+=a[i];
    while(j<=i&&m<(i-j+1)*a[i]-s) s-=a[j++];
    ans=max(ans, i-j+1);
  }
  cout<< ans<< '\n';
  return 0;
}