#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
void dfs(int samN, int c, int id){
    if(c == m){
        ans = max(samN, ans);
        return;
    }
    for(int i = id + 1; i <= n; i++){
        dfs((samN & a[i]), c + 1, i);
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i <= n - m; i++){
        dfs(a[i], 1, i);
    }
    cout << ans;
    return 0;
}
