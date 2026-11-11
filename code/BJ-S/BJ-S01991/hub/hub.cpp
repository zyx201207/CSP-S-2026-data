#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;

int c, t;
vector<int> G[N];
int dis[N];

int bfs(int st, int en){
    queue<int> q;
    q.push(st);
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : G[u]){
            if(dis[u] + 1 < dis[v]){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[en];
}

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            G[i].clear();
        }
        for(int i = 1; i <= n - 1; i ++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(k == 2){
            int ans = 1e9;
            for(int i = 1; i < n; i++){
                for(int j = i + 1; j <= n; j++){
                    int minn1 = 1e9;
                    for(int k = 1; k <= n; k++){
                        if(k == i) continue;
                        minn1 = min(minn1, bfs(i, k));
                    }
                    int minn2 = 1e9;
                    for(int k = 1; k <= n; k++){
                        if(k == j) continue;
                        minn2 = min(minn2, bfs(j, k));
                    }
                    int cur = max(minn1, minn2);
                    ans = min(ans, cur);
                }
            }
            cout << ans << '\n';
        }
        else if(k == 1){
            int ans = 1e9;
            for(int i = 1; i <= n; i++){
                int minn = 1e9;
                for(int k = 1; k <= n; k++){
                    if(k == i) continue;
                    minn = min(minn, bfs(i, k));
                }
                ans = min(ans, minn);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
