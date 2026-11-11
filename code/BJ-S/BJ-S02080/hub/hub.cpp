#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int nn = 1e6 + 5;
vector<int> e[nn];
int n, k, h[nn], ans, dis[20];
bool a[nn];
int head(int x){return h[x] == x ? x : h[x] = head(h[x]);}
int bfs(int s){
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(a[u]) return dis[u];
        for(int v : e[u]){
            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return 1;
}
void dfs(int x, int y){
    // cout << "CRY" << x << ' ' << y << endl;
    if(k - y > n - x + 1 || y > k) return;
    if(x == n + 1){
        if(y != k) return;
        // cout << "FRY" << endl;
        for(int i = 1; i <= n; ++i) h[i] = i;// cout << a[i] << ' ';
        // cout << '\n';
        for(int i = 1; i <= n; ++i){
            if(a[i])
                for(int j : e[i])
                    if(a[j] && head(i) != head(j)) h[head(i)] = head(j);
        }
        // cout << "CRY" << endl;
        int w = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] && head(i) != head(1) && w == 0) w = head(i);
            else if(a[i] && head(i) != w && head(i) != 1) return;
        }
        // cout << "CRY" << endl;
        int res = 0;
        for(int i = 1; i <= n; ++i){
            if(!a[i]){
                res = max(res, bfs(i));
            }
        }
        ans = min(ans, res);
        return;
    }
    a[x] = 0;
    dfs(x + 1, y);
    a[x] = 1;
    dfs(x + 1, y + 1);
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; ++i) e[i].clear(), a[i] = 0;
        for(int i = 1; i < n; ++i){
            int u, v;
            scanf("%d %d", &u, &v);
            e[u].emplace_back(v); e[v].emplace_back(u);
        }
        if(c <= 3){
            ans = 1e9;
            dfs(1, 0);
            printf("%d\n", ans);
        }else if(c >= 13 && c <= 14){

        }
    }
    return 0;
}