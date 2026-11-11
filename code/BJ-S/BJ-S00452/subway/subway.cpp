#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, maxm = 5e5+10;
int n, c, m, d, q;
int w[maxm], k[maxn], a[maxn][maxm], t[maxn][maxm], x[maxm], y[maxm];
bool vis[maxm], vis2[maxm];
vector<int> ve[maxn], ve2[maxm], ve3[maxm];
long long ans, dis[maxm];
struct node{
    int dis;
    int id;
    bool operator <(const node&x) const{
        return x.dis < dis;
    }
};
int dijkstra(int s){
    priority_queue<node> q;
    q.push({0, s});
    vis2[s] = true;
    for(int i = 1;i <= m;i++) dis[i] = 1e18;
    dis[s] = 0;
    while(!q.empty()){
        int a = q.top().id;
        if(vis2[a]) continue;
        vis2[a] = true;
        for(int i = 0;i < ve3[a].size();i++){
            int tmp = ve3[a][i];
            if(dis[tmp] > dis[a] + 2 * t[1][1]){
                dis[tmp] = dis[a] + 2 * t[1][1];
                if(!vis2[tmp]) q.push({dis[tmp], tmp});
            }
        }
    }
}
void solve(){
     for(int i = 1;i <= m;i++){
        if(ve2[i].size() > 1) vis[i] = true;
        for(int j = 1;j <= ve2[i].size();j++){
            for(int k = 1;k <= ve[ve2[i][j]].size();k++){
                if(vis[ve[ve2[i][j]][k]]){
                    ve3[i].push_back(ve[ve2[i][j]][k]);
                    ve3[ve[ve2[i][j]][k]].push_back(i);
                }
            }
        }
     }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t[i][j];
            ve[i].push_back(a[i][j]);
            ve2[a[i][j]].push_back(i);
        }
    }
    solve();
    for(int i = 1;i <= q;i++){
        cin >> x[i] >> y[i];
        dijkstra(x[i]);
        ans = w[x[i]] + dis[y[i]] + w[y[i]] + 2 *t[1][1];
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
