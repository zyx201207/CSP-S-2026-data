#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
long long maxx = -1;
long long ans = 0;
bool vis[N];
long long ans2 = 7;
void dfs(int num, int ans1){
    if(num == m){
        ans2 = max(ans2, 1ll * ans1);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(num + 1, ans1&a[i]);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        maxx = max(maxx, 1ll * a[i]);
        ans &= a[i];
    }
    if(m == 1){
        cout << maxx;
        return 0;
    }
    else if(m == n){
        cout << ans;
        return 0;
    }
    else if(m == 2){
            long long ma = -1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                ma = max(ma, 1ll * a[i]&a[j]);
            }
        }
        cout << ma;
    }
    else{
        dfs(0, 0);
        cout << ans2;
    }
    return 0;
}

