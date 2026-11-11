#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5+5;
long long w[M], k[N], c, n, m, d, q, x, y;
vector<int> a[N], t[N], bel[M], loc[M];
long long dis[N], vis[N];
struct node{
    int id;
    long long val;
    bool operator <(const node & other) const{
        return val > other.val;
    }
};
priority_queue<node> pq;
long long dij(int x, int y){
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    int len = bel[x].size();
    for(int i = 0; i < len; i++){
        dis[bel[x][i]] = t[bel[x][i]][loc[x][i]];
        pq.push({bel[x][i], t[bel[x][i]][loc[x][i]]});
        vis[bel[x][i]] = 1;
    }
    while(pq.size()){
        long long u = pq.top().id, val = pq.top().val;
        pq.pop();
        vis[u] = 1;
        for(int i = 0; i < k[u]; i++){
            int len = bel[a[u][i]].size();
            for(int j = 0; j < len; j++){
                if(bel[a[u][i]][j] != u && !vis[bel[a[u][i]][j]]){
                    long long nval = val + t[u][i] + t[bel[a[u][i]][j]][loc[a[u][i]][j]];
                    pq.push({bel[a[u][i]][j], nval});
                    dis[bel[a[u][i]][j]] = min(dis[bel[a[u][i]][j]], nval);
                }
            }
        }
    }
    long long res = 0x3f3f3f3f3f3f3f3f;
    len = bel[y].size();
    for(int i = 0; i < bel[y].size(); i++){
        res = min(res, dis[bel[y][i]] + t[bel[y][i]][loc[y][i]]);
    }
    return res;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 0; j < k[i]; j++){
            int tmp1, tmp2; cin >> tmp1 >> tmp2;
            a[i].push_back(tmp1);
            t[i].push_back(tmp2);
            bel[tmp1].push_back(i);
            loc[tmp1].push_back(j);
        }
    }
    while(q--){
        cin >> x >> y;
        cout << dij(x, y) + w[x] + w[y] << '\n';
    }
    return 0;
}