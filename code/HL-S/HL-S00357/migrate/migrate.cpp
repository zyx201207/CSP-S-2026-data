#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e3 + 5, inf = 2e18;
int c, t, n, d, a[maxn], dis[maxn], cnt[maxn], ans;
vector <int> g[maxn];
bool vis[maxn];
struct node{
    int to, w;
    friend bool operator < (node a, node b) {
        return a.w > b.w;
    }
 };
priority_queue <node> q;
void dij(int s){
    memset(dis, 100, sizeof(dis));
    dis[s] = 0;
    q.push({s, 0});
    while(!q.empty()){
        node t = q.top(); q.pop();
        int u = t.to;
        vis[u] = 1;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(dis[v] == dis[u] + 1){
                cnt[v]++;
            }
            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                cnt[v] = 1;
                q.push({v, dis[v]});
            }
        }
    }
    return;
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
            	if(i == j) continue;
                if(abs(a[i] - a[j]) <= d){
                    g[i].push_back(j);
                }
            }
        }
            for(int i = 1; i <= n; i++){
                dij(i);
                for(int i = 1; i <= n; i++)if(cnt[i] == 2) ans++;
                memset(vis, 0, sizeof(vis));
                memset(cnt, 0, sizeof(cnt));
            }
            ans /= 2;
            cout << ans << '\n'; ans = 0;
            for(int i = 1; i <= n; i++)g[i].clear();
    }
    return 0;
}
