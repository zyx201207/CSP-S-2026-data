#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
bool vis[200005];
int ans;
void dfs(int num, int an){
    if (num == m){
        if (an > ans){
            ans = an;
        }
        return ;
    }
    for (int i = 1; i <= n; i++){
        if (vis[i] == 0){
            vis[i] = 1;
            dfs(num + 1, an & a[i]);
            vis[i] = 0;
        }
    }
    return ;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
            cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        vis[i] = 1;
        dfs(1, a[i]);
        vis[i] = 0;
    }
    cout << ans;
    return 0;
}
