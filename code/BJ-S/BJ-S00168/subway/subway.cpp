#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

const int N = 55;
const int MQ = 5e5 + 5;
const int inf = 0x3f3f3f3f;

int c, n, m, d, q;
long long ans = 0;
int w1[MQ];
pii begi[MQ];
int yl = 0;
int nt[MQ][N];
int a[N][N], t[N][N], k[MQ];
int x, y;

bool vis[MQ];
int dis[MQ];
int ecnt = 0, to[2 * MQ], nxt[2 * MQ], head[2 * MQ], w[2 * MQ], lin[2 * MQ];

priority_queue<tii, vector<tii>, greater<tii>> pq;

void add(int line, int u, int v){
    to[ecnt++] = v;
    lin[ecnt] = line;
    w[ecnt] = t[line][u];
    nxt[ecnt] = head[u];
    head[u] = ecnt;

    to[ecnt++] = u;
    lin[ecnt] = line;
    w[ecnt] = t[line][u];
    nxt[ecnt] = head[v];
    head[v] = ecnt;
}

int dji(){
    for(int i = 1; i <= m; i++) dis[i] = inf, vis[i] = false;
    vis[x] = true;
    dis[x] = begi[x].first;
    pq.push({begi[x].first, x, begi[x].second});
    while(!pq.empty()){
        if(vis[y]) break;
        tii o = pq.top();
        pq.pop();
        int d = get<0>(o), u = get<1>(o), li = get<2>(o);
        if(vis[u]) continue;
        if(u == y) yl = u;
        vis[u] = true;
        for(int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            if(li == lin[i]){
                if(dis[v] > dis[u]){
                    dis[v] = dis[u];
                    pq.push({dis[u], v, li});
                }
            }else{
                if(dis[v] > w[i] + nt[u][li] + dis[u]){
                    dis[v] = w[i] + nt[u][li] + dis[u];
                    pq.push({dis[v], v, lin[i]});
                }
            }
        }
    }
    return dis[y];
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1; i <= m; i++) cin>>w1[i];
    for(int i = 1; i <= n; i++){
        cin>>k[i];
        for(int j = 1; j <= k[i]; j++){
            cin>>a[i][j]>>t[i][j];
            if(begi[a[i][j]].first > t[i][j]){
                begi[a[i][j]].first = t[i][j];
                begi[a[i][j]].second = i;
            }
            nt[a[i][j]][i] = t[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < k[i]; j++){
            add(i, a[i][j], a[i][j + 1]);
        }
    }
    while(q--){
        cin>>x>>y;
        ans += w1[x] + w1[y] + dji() + begi[x].first + nt[y][yl];
        cout<<ans<<"\n";
    }
    return 0;
}