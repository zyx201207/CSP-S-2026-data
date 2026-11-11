#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[200005];
bool v[200005];
int ans = INT_MIN;

void dfs(int x, int res, int cnt){
    if (cnt > m){
        return ;
    }
    if (cnt == m){
        ans = max(ans, res);
        return ;
    }
    if (n-x < m-cnt){
        return ;
    }
    if (res < ans){
        return ;
    }
    dfs(x+1, res, cnt);
    for (int i=1; i<=n; i++){
        if (v[i]){
            continue ;
        }
        v[i] = 1;
        dfs(x+1, res&a[i], cnt+1);
        v[i] = 0;
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    if (m == 1){
        for (int i=1; i<=n; i++){
            ans = max(ans, a[i]);
        }
    }
    else if (m == n){
        ans = a[1];
        for (int i=1; i<=n; i++){
            ans = ans&a[i];
        }
    }
    dfs(0, -1, 0);
    cout<<ans<<endl;

    return 0;
}
