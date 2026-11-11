#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int M = 2e31 - 1;
int n, m, a[N], ans, vis[N];
void dfs(int k, int sum){
    if(k == m){
        ans = max(ans, sum);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(k + 1, sum & a[i]);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(0, M);
    cout << ans;
    return 0;
}
