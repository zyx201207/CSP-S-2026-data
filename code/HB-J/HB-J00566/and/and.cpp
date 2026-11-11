#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;

int n, m, a[N], ans = -1;
bool vis[N];

void dfs(int cnt, int val){
    if(cnt == m){
        ans = max(ans, val);
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(vis[i] == false){
            vis[i] = true;
            dfs(cnt + 1, val & a[i]);
            vis[i] = false;
        }
    }
}

signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n <= 2000){
        for(int i = 1; i <= n; i++){
            vis[i] = true;
            dfs(1, a[i]);
            vis[i] = false;
        }
        cout << ans;
    } else {
        stable_sort(a + 1, a + 1 + n);
        reverse(a + 1, a + 1 + n);
        cout << a[m];
    }
    return 0;
}


