#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 55, M = 1e5 + 10;
int c, n, d, Q;
long long m, k, ans = 0;
long long w[M], a[N][M], t[N][M], vis[M], dis[N];
int cnt = 0, hd[M];
struct edge{
    long long u, v, w, nxt;
}e[M];
void addedge(long long u, long long v, long long w){
    e[++cnt] = edge{u, v, w, hd[u]};
    hd[u] = cnt;
}
struct node{
    long long u, ds;
    bool operator < (const node &t) const{
        return ds > t.ds;
    }
};
priority_queue<node> q;
void djstl(long long x){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push(node{x, 0});
    dis[x] = 0;
    while(!q.empty()){
        long long u = q.top().u, ds = q.top().ds;
        q.pop();
        if(vis[u])
            continue;
        vis[u] = 1;
        for(int i = hd[u]; i > 0; i = e[i].nxt){
            long long v = e[i].v, w = e[i].w;
            if(dis[v] > ds + w){
                dis[v] = ds + w;
                q.push(node{v, dis[v]});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(long long j = 1; j <= k; j++){
            cin >> a[i][j] >> t[i][j];
        }
        for(long long u = 1; u <= k; u++){
            for(long long v = u + 1; v <= k; v++){
                addedge(a[i][u], a[i][v], t[i][u] + t[i][v]);
                addedge(a[i][v], a[i][u], t[i][u] + t[i][v]);
            }
        }
    }
    while(Q--){
        long long x, y;
        cin >> x >> y;
        djstl(x);
        cout << dis[y] + w[y] + w[x]<< endl;
    }
    return 0;
}