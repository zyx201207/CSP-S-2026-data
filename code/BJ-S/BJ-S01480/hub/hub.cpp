#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> edge[N];
int dis[N], f[N];
int u[N], v[N];
void bfs(int s){
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto i : edge[u]){
            if (dis[i] > dis[u] + 1){
                dis[i] = dis[u] + 1;
                q.push(i);
            }
        }
    }
}
int fnd(int x){
    return (x == f[x] ? x : f[x] = fnd(f[x]));
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c, t; cin >> c >> t;
    while (t--){
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) edge[i].clear();
        for (int i = 1; i < n; i++){
            cin >> u[i] >> v[i];
            edge[u[i]].push_back(v[i]);
            edge[v[i]].push_back(u[i]);
        }
        int ans = INT_MAX;
        if (k == 2){
            for (int i = 1; i < n; i++)
                for (int j = i + 1; j <= n; j++){
                    memset(dis, 0x3f, sizeof(dis));
                    dis[i] = dis[j] = 0;
                    bfs(i); bfs(j);
                    int maxn = -1;
                    for (int i = 1; i <= n; i++) maxn = max(maxn, dis[i]);
                    ans = min(ans, maxn);
                }
            cout << ans << endl;
        }
        else{
            memset(f, 0, sizeof(f));
            int S = 1 << n;
            for (int s = 0; s < S; s++){
                int cnt = 0;
                for (int i = 0; i < n; i++){
                    if (s >> i & 1){
                        cnt++;
                        f[i + 1] = i + 1;
                    }
                }
                if (cnt != k) continue;
                for (int i = 1; i < n; i++)
                    if (f[u[i]] && f[v[i]])
                        f[fnd(u[i])] = fnd(v[i]);
                set<int> st;
                for (int i = 1; i <= n; i++)
                    if (f[i])
                        st.insert(f[i]);
                if (st.size() > 2) continue;
                memset(dis, 0x3f, sizeof(dis));
                for (int i = 0; i < n; i++){
                    if (s >> i & 1){
                        dis[i] = 0;
                    }
                }
                for (int i = 0; i < n; i++){
                    if (s >> i & 1){
                        bfs(i);
                    }
                }
                int maxn = -1;
                for (int i = 1; i <= n; i++) maxn = max(maxn, dis[i]);
                ans = min(ans, maxn);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
