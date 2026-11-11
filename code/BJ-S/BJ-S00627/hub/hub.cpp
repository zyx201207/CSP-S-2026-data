#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int c, T, n, k;
struct edge{
    int nxt, to;
}e[2 * N];
int head[N], tot;
void add(int u, int v){
    e[++tot] = {head[u], v};
    head[u] = tot;
}
int f[N];//下面有多少选中人
int dis[N];//距离最远有多远
int g[N];//选中的最小距离
int vis[N];//多个使用个数
bool qp[N];
void dfs(int u, int frm, int limit){//处理f, dis, g
    f[u] = dis[u] = vis[u] = qp[u] = 0; g[u] = inf;
    int minn = inf, maxn = 0;//minn:选中最近 maxn:距离最远
    int tmp = 0;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to;
        if(v == frm) continue;
        dfs(v, u, limit);
        maxn = max(maxn, dis[v] + 1);
        minn = min(minn, g[v] + 1);
        if(f[v]) ++vis[u];
        f[u] += f[v];
        if(f[v]) tmp = f[v];
    }
    if(minn + maxn <= limit){
        g[u] = minn;
        dis[u] = 0;
    }else{//最远的无法摆平
        dis[u] = maxn;
        g[u] = minn;
    }
    if((u == 1 && minn + maxn > limit) || dis[u] >= limit){
        // cout << " " << u << endl;
        qp[u] = true;
        g[u] = 0;
        dis[u] = -limit;
        ++f[u];
    }
    // if(g[u] <= limit) dis[u] = g[u] - limit;
    // if(f[u] != tmp) cout << u << " " << frm << " " << f[u] << " " << g[u] << " " << dis[u] << " " << minn << " " << maxn << endl;
}
void dfs2(int u, int frm){
    if(qp[u]) g[u] = 0;
    else g[u] = inf;
    int tmp = 0;
    int pp = 0;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to;
        if(v == frm) continue;
        dfs2(v, u);
        if(f[v]) {tmp = f[v]; pp = g[v] + 1;}
        g[u] = min(g[u], g[v] + 1);
    }
    // if(f[u] != tmp) cout << u << " " << frm << " " << f[u] << " " << g[u] << " " << dis[u] << " " << pp << endl;
}
int maxe, sume;//新图的边权最大/和
void js(int u, int frm){//注意u==1要特殊判断
    int sum = 0;
    if(qp[u] || vis[u] > 2) g[u] = 0;
    else g[u] = inf;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to;
        if(v == frm) continue;
        js(v, u);
        if(f[v] && g[u] != 0) g[u] = g[v] + 1;
        if(vis[u] == 2 && f[u] == f[1]){
            if(f[v]) sum += g[v];
        }else if(f[v] && (vis[u] > 2 || g[u] == 0)){//截断!
            // cout << u << " " << v << "  " << g[v] << endl;
            sume += g[v];
            maxe = max(maxe, g[v]);
        }
    }
    if(qp[u] || vis[u] > 2) g[u] = 0;
    if(vis[u] == 2 && f[u] == f[1]){
        ++sum;
        // cout << u << " " << sum << endl;
        sume += sum;
        maxe = max(maxe, sum);
    }
}
bool check(int x){//<=x是不是有可能
    // cout << x << "--------------------" << endl;
    dfs(1, 0, x);
    if(f[1] > k) return 0;
    for(int i = 1; i <= n; ++i){
        if(f[i] != f[1]) ++vis[i];
    }
    dfs2(1, 0);
    sume = maxe = 0;
    js(1, 0);
    // cout << f[1] << " " << sume << " " << maxe << endl;
    return (f[1] + sume - maxe <= k);
}
void clear(){
    tot = 0;
    for(int i = 1; i <= n; ++i){
        head[i] = 0;
    }
}
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> k;
        // cout << k << endl;
        for(int i = 1; i < n; ++i){
            int u, v;
            cin >> u >> v;
            add(u, v); add(v, u);
        }
        if(n == k){
            cout << 0 << endl;
            clear();
            continue;
        }
        int l = 1, r = n - k;
        int ans = 0;
        while(l <= r){
            int mid = l + r >> 1;
            if(check(mid)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
        clear();
    }
    return 0;
}/*
T4 hub 研发基地
二分答案呢 如何保证使用城市数
    在不考虑连通块情况下，极其容易DP 问题转化为如何在有边权的树上连接到两个连通块-最小生成树??? - 只需要知道最大边
        如何建新图 - 对于“上面有人”的节点，若其为某两个的LCA，则一定选取 度数>=3
    等等等等等等这是T4吗 核弹摊坐，椅子爆炸
考虑一个连通块非常好做 两个如何转移
考虑f[u][i][3][2] 表示u子树内用了i座城市，几个连通块，这个点有没有选上的最小代价（子树内代价）
    O(nk)? 65pts???
连通块数不超过2
看到恰好 - 不是显然<=的情况也是对的
*/