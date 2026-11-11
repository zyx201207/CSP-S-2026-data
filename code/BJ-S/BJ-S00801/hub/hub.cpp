#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
    ll x = 1,s = 0;
    char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') x = -1;
    for (;isdigit(c);c = getchar()) s = s * 10 + c - '0';
    return x * s;
}
int c,box[15],t,n,k,u,v,ans,s,vis[15],dis[15];
vector<int> g[15];
void check(int u){
    vis[u] = 1;
    for (int i = 0;i < g[u].size();++i){
        int v = g[u][i];
        if (box[v] && !vis[v]) check(v);
    }
}
queue<int> q;
int bfs(int u){
    while (!q.empty()) q.pop();
    memset(dis,0x3f,sizeof(dis));
    dis[u] = 0;
    q.push(u);
    int sum = 0;
    while (!q.empty()){
        int s = q.front();
        q.pop();
        if (box[s]){
            sum = dis[s];
            break;
        }
        for (int i = 0;i < g[s].size();++i){
            int j = g[s][i];
            if (dis[j] == 0x3f3f3f3f) dis[j] = dis[s] + 1,q.push(j);
        }
    }
    return sum;
}
void dfs(int u){
    if (u == n + 1){
        memset(vis,0,sizeof(vis));
        int sum = 0;
        for (int i = 1;i <= n;++i) sum += box[i];
        if (sum != k) return;
        s = 0;
        for (int i = 1;i <= n;++i)
            if (box[i] && !vis[i]){
                check(i);
                ++s;
            }
        if (s > 2) return;
        int cnt = 0;
        for (int i = 1;i <= n;++i) cnt = max(cnt,bfs(i));
        ans = min(ans,cnt);
        return;
    }
    box[u] = 0;
    dfs(u + 1);
    box[u] = 1;
    dfs(u + 1);
}
void subtask1(){
    while (t--){
        cin >> n >> k;
        ans = n;
        for (int i = 1;i <= n;++i) g[i].clear();
        for (int i = 1;i < n;++i){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        cout << ans << '\n';
    }
}
void subtask2(){
    while (t--){
        cin >> n >> k;
        int m = (n - 1) / 2;
        for (int i = 1;i < n;++i){
            cin >> u >> v;
        }
        if (k == n) cout << 0 << '\n';
        else if (k == 1) cout << (n + 3) / 4 << '\n';
        else cout << ((n + 1) / 2 - k + 6) / 4 << '\n';
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    if (c <= 3) subtask1();
    else if (c == 13 || c == 14) subtask2();
    return 0;
}
