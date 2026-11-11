#include<bits/stdc++.h>
using namespace std;
int n, k, mx = INT_MIN, cnt, ans = INT_MIN;
vector<int>a(n);
void dfs(int i, int x, int t){
    if(t >= k){
        ans = max(x, ans);
        cout << ans <<"\n";
        return;
    }//cout<<1;
    if(i >= n)return;
    dfs(i + 1, x, t);
    if(t!=0)dfs(i + 1, x & a[i], t + 1);
    else dfs(i + 1,a[i], t + 1);
}
void solve(){
    cin >> n >> k;
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        cnt &= a[i];
        mx = max(mx, a[i]);
    }
    sort(a.begin(), a.end(), greater<int>());
    if(k == 1){
        cout << mx;
    }
    else if(k == 2){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(k == n){
        cout << cnt;
    }
    else if(n > 2000){
        ans = a[n-k];
        cout << ans;
    }
    else{
        dfs(0,0,0);
        cout << ans;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
