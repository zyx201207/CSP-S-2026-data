#include <bits/stdc++.h>
#define N 1010
#define int long long
using namespace std;
int dp[N][N];
int answer;
bool vis[N];
bool dis[N];
int n, k;
void dfs2(int x){
    dis[x] = true;
    for(int i = 1; i <= n; i++){
        if(dp[x][i] != 1){
            continue;
        }
        if(!dis[i] && vis[i]){
            dfs2(i);
        }
    }
}
bool check(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        dis[i] = false;
    }

    for(int i = 1; i <= n; i++){
        if(!dis[i] && vis[i]){
            sum++;
            dfs2(i);
        }
    }
    return sum <= 2;
}
void dfs(int step, int total){
    if(total > k){
        return ;
    }
    if(step > n){
        if(total == k && check()){
            int maxn = 0;
            for(int i = 1; i <= n; i++){
                int minn = 1e18;
                for(int j = 1; j <= n; j++){
                    if(vis[j]){
                        minn = min(minn, dp[i][j]);
                    }
                }
                maxn = max(maxn, minn);
            }
            answer = min(answer, maxn);
        }
        return ;
    }
    vis[step] = true;
    dfs(step + 1, total + 1);
    vis[step] = false;
    dfs(step + 1, total);
}
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, q;
    cin >> c >> q;
    while(q--){
        answer = 1e18;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = 1e18;
            }
        }
        for(int i = 1; i <= n; i++){
            dp[i][i] = 0;
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            dp[u][v] = 1;
            dp[v][u] = 1;
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(i == j || j == k || i == k){
                        continue;
                    }
                    dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
                }
            }
        }
        dfs(1, 0);
        cout << answer << "\n";
    }
    return 0;
}

