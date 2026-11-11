# include <bits/stdc++.h>
using namespace std;
# define int long long
const int M = 5e5+5+505, N = 505;
int dis[M], W[N], f[N][N];
vector < pair <int,int> > g[M];
priority_queue < pair <int,int> > q;

int dij(int st, int en){
    memset(dis,0x3f,sizeof dis);
    dis[st] = 0;
    q.push({0, st});
    while (!q.empty()){
        int u = q.top().second, ww = q.top().first;
        q.pop();
        if (-ww > dis[u]) continue ;

        for (pair <int,int> tmp : g[u]){
            int v = tmp.first, w = tmp.second;
            if (dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
    return dis[en];
}

void go1(){
    int n,m,d,q;
    cin >> m >> n >> d >> q;
    for (int i=1;i<=n;i++){
        cin >> W[i];
    }
    for (int i=1;i<=m;i++){
        int t;
        cin >> t;
        for (int j=1;j<=t;j++){
            int u,w;
            cin >> u >> w;
            g[u].push_back({n+i, w});
            g[n+i].push_back({u, w});
        }
    }
    while (q--){
        int x,y;
        cin >> x >> y;
        cout << dij(x, y) + W[x] + W[y] << endl;
    }

}

void go2(){
    memset(f, 0x3f, sizeof f);
    int m,n,d,q;
    cin >> m >> n >> d >> q;
    for (int i=1;i<=n;i++){
        cin >> W[i];
        f[i][i] = 1;
    }
    for (int i=1;i<=m;i++){
        int t;
        cin >> t;
        if (t == 1){
            cin >> t >> t;
            continue ;
        }
        else{
            int u,w1,v,w2;
            cin >> u >> w1 >> v >> w2;
            f[u][v] = f[v][u] = min(f[u][v], w1+w2);
        }
    }

    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    while (q--){
        int x,y;
        cin >> x >> y;
        cout << W[x] + W[y] + f[x][y] << endl;
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c;
    cin >> c;
    if (c <= 8){
        go1();
        return 0;
    }
    if (c <= 11){
        go2();
        return 0;
    }

    int m,n,d,q,sb=1e18;
    cin >> m >> n >> d >> q;
    for (int i=1;i<=n;i++){
        cin >> W[i];
    }
    for (int i=1;i<=m;i++){
        int t;
        cin >> t;
        if (t == 1){
            cin >> t >> t;
            continue ;
        }
        int u,v,w1,w2;
        cin >> u >> w1 >> v >> w2;
        sb = min(sb, w1 + w2);
    }

    while (q--){
        int u,v;
        cin >> u >> v;
        cout << W[u] + W[v] + sb << endl;
    }

    return 0;
}
