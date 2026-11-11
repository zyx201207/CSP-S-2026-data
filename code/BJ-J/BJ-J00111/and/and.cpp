#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int n, m;
int yu(int x, int y){
    string xx = "", yy = "";
    while(x > 0){
        xx = (char)(x % 2 + '0') + xx;
        x /= 2;
    }
    while(y >= 1){
        yy = (char)(y % 2 + '0') + yy;
        y /= 2;
    }
    //cout << xx << " " << yy << '\n';
    //cout << "\n";
    int wq = 1;
    int ans = 0;
    for(int i = 1; i <= min(yy.size(), xx.size()); i++){
        if(yy[yy.size() - i] == '1' && xx[xx.size() - i] == '1') ans += wq;
        wq *= 2;
    }
    //cout << ans << '\n';
    return ans;
}
int dfs(int x, int cnt, int i){
    //cout << x << "cnt: " << cnt << "i: " << i << '\n';
    if(cnt >= m){
        return x;
    }
    if(i == n && cnt < m) return 0;
    int ans = 0;
    for(int j = i + 1; j <= n; j++){
        ans = max(ans, dfs(yu(x, a[j]), cnt + 1, j));
    }
    return ans;
}
int main(){
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  if(m == 1){
    sort(a + 1, a + 1 + n);
    cout << a[n];
    return 0;
  }
  if(m == n){
    int ans = a[1];
    for(int i = 2; i <= n; i++){
        ans = yu(ans, a[i]);
    }
    cout << ans;
    return 0;
  }
  if(m == 2){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            ans = max(ans, yu(a[i], a[j]));
        }
    }
    cout << ans;
    return 0;
  }
    int ans = 0;
    for(int i = 1; i <= n - m + 1; i++){
        ans = max(dfs(a[i], 1, i), ans);
    }
    //cout << endl;
    cout << ans;
}
