//陈超 GZ-S00200 盘州市第二中学
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 502010, M = N * 2;
const LL INF = 0x3f3f3f3f3f3f3f3f;

/*
口与厅不需要边
计算以每个站台为起点的最短路
*/

int c, n, m, d, q;
int e[M], ne[M], h[N], idx;
int ju[N];
int w[M];
LL dist[504][450510];
bool st[500010];

struct node{
    LL dis; int ver;
    bool operator<(const node &x)const{
        dis < x.dis;
    }
};

void add(int a, int b, int c){
    e[++idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx;
}

void dij(int u){
    priority_queue<node> heap;
    heap.push({0, m + u});
    dist[u][m+u] = 0;
    while(heap.size()){
        auto t = heap.top(); heap.pop();
        int ver = t.ver; LL dis = t.dis;
        if(!st[ver]) continue;
        st[ver] = false;
        for(int i = h[ver]; i; i = ne[i]){
            int j = e[i];
            if(dis + w[i] < dist[u][j]){
                dist[u][j] = dis + w[i];
                st[j] = true;
                heap.push({dist[u][j], j});
            }
        }
    }
}

void solve(){
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m + n; j++)
            dist[i][j] = INF;
    for(int i = 1; i <= m; i++){
        cin >> ju[i];
    }
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        for(int j = 1; j <= k; j++){
            int to, x;
            cin >> to >> x;
            add(to, i + m, x), add(i + m, to, x);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m + n; j++) st[j] = 1;
        dij(i);
    }
    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << dist[i][j] << " \n"[j == m];
        }
    }*/
    while(q--){
        int x, y;
        cin >> x >> y;
        LL ans = INF;
        for(int i = 1; i <= n; i++){
            ans = min(ans, (LL)dist[i][x] + dist[i][y]);
        }
        ans += ju[x] + ju[y];
        cout << ans << endl;
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int T = 1;
    while(T--) solve();
    return 0;
}
