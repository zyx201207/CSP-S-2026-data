#include<bits/stdc++.h>
using namespace std;

int n, m, a[200002];
int b[22], ans = -1;
bool vis[22];

void dfs(int x){
    if(x == m + 1){
        int t = INT_MAX;
        for(int i = 1;i <= m;i++){
            t &= a[b[i]];
        }
        ans = max(ans, t);
        return;
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i] && a[i] > b[x-1]){
            b[x] = i;
            vis[i] = true;
            dfs(x + 1);
            vis[i] = false;
        }
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    if(m == n){
        int ans = INT_MAX;
        for(int i = 1;i <= n;i++){
            ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    if(m == 1){
        cout << a[1];
        return 0;
    }
    if(n <= 2000 && m == 2){
        int ans = -1;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == j) continue;
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}