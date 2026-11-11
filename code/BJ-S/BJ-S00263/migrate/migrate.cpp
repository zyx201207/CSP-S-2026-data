#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 7;
int c, t, n, d;
bool vis[maxn][maxn];
ll a[maxn], dis[maxn][maxn], cnt[maxn][maxn];
void Dijkstra(int start) {
    set<pair<int, int> > s;
    dis[start][start] = 0;
    cnt[start][start] = 1;
    for(int i = 1; i <= n; i ++) {
        ll id = -1, minj = numeric_limits<ll>::max();
        for(int j = start; j <= n; j ++) 
            if(!vis[start][j] && dis[start][j] < minj) 
                minj = dis[start][j], id = j;
        vis[start][id] = true;
        for(int j = id + 1; j <= n; j ++) 
            if(abs(a[id] - a[j]) <= d) {
                if(dis[start][id] + 1 < dis[start][j]) 
                    dis[start][j] = dis[start][id] + 1, cnt[start][j] = cnt[start][id];
                else if(dis[start][id] + 1 == dis[start][j]) 
                    cnt[start][j] += cnt[start][id];
            }
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t --) {
        memset(dis, 0x3f, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, false, sizeof(vis));
        cin >> n >> d;
        for(int i = 1; i <= n; i ++) 
            cin >> a[i];
        for(int i = 1; i <= n; i ++) 
            Dijkstra(i);
        ll ans = 0;
        for(int i = 1; i <= n; i ++) 
            for(int j = i + 1; j <= n; j ++) 
                if(cnt[i][j] == 2) 
                    ++ ans;
        cout << ans << '\n';
    }
}