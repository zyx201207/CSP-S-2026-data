#include<bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 5e5 + 5;

LL m, a[N];
queue<LL>q;
int n, ans;

int main(){
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; i++){
    if(a[i] != a[i - 1]){
      m -= 1ll * (a[i] - a[i - 1]) * (int)q.size();
    }
    q.push(a[i]);
    for(; m < 0; q.pop()){
      LL x = q.front();
      m += a[i] - x;
    }
    ans = max(ans, (int)q.size());
  }
  cout << ans;
  return 0;
}
