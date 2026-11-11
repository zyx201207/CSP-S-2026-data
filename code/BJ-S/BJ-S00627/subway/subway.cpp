#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int M = 6e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[M];
struct edge{
    int v, w;//存虚点编号时+m
}e[2 * M];//只需要到虚点即可，无需虚点到其
vector<edge> mp[M];//方便枚举
int f[N][N];//任意两个虚点之间的距离
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i){
        cin >> w[i];
    }
    for(int i = 1; i <= n; ++i){
        int k;
        cin >> k;
        for(int j = 1; j <= k; ++j){
            int u, w;
            cin >> u >> w;
            mp[u].push_back({i + m, w});
        }
    }
    //预处理任意虚点距离
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i != j) f[i][j] = inf;
        }
    }
    for(int u = 1; u <= m; ++u){
        for(int i = 0; i < mp[u].size(); ++i){
            int v1 = mp[u][i].v - m, w1 = mp[u][i].w;
            for(int j = i + 1; j < mp[u].size(); ++j){
                int v2 = mp[u][j].v - m, w2 = mp[u][j].w;
                f[v1][v2] = min(f[v1][v2], w1 + w2);
                f[v2][v1] = min(f[v2][v1], w1 + w2);
            }
        }
    }
    for(int k = 1; k <= n; ++k){//floyd
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    //处理询问
    while(q--){
        int x, y, ans = inf;
        cin >> x >> y;
        for(int i = 0; i < mp[x].size(); ++i){
            int v1 = mp[x][i].v - m ,w1 = mp[x][i].w;
            for(int j = 0; j < mp[y].size(); ++j){
                int v2 = mp[y][j].v - m, w2 = mp[y][j].w;
                ans = min(ans, f[v1][v2] + w1 + w2);
            }
        }
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}/*
T2 subway 地铁
深度思考ing...
考虑首先试图得到任意两个虚点之间的距离，随后对于每个询问两边分别枚举用的是哪个虚点即可
    如何处理任意两个虚点之间距离-对每个点首先连接，而后floyd即可
    好题，青吧
显然每次必经过虚点，所以任意两点之间路径条数不超过2n
n<=2时如何?
d<=2时如何?
考虑为什么 n 很小 d 很小
对于一条线路，可转化为加到虚点点权为0
    然后本质加到边上最短路即可O(min(m^2 log n, qm logm))解决 44pts
    对于性质 B 可以 bfs O(m^2) 解决
你引起我的兴趣了
n <= 500  m, sum(k) <= 5e5 d <= 20
总步行时长尽可能小
注意有点的时间
m个地铁站n条线路吗有点意思
B市是BJ吗qwq
*/