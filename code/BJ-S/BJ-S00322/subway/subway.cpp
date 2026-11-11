/*
思路：枚举两个线路，换乘到那个线路的最短路，n^3
询问枚举起点和终点乘坐的线路。d^2*q
时间复杂度 O(n^3+d^2*q)，5/4e8，有点炸。这个列缺霹雳台式机应该是过不了的
细节输入前三个变量是cnm

16:34大样例过了，不过后面两个都是0.98s
不过这个雷霆霹雳台式机连4e8次%998244353都得花三秒钟，应该是能过的。
优势在我
魏鹏飞老师经典语录：我难他亦男，我不畏难；我易他亦易，我不忘了。所以这次分数线应该会很高。所以我还需要拼一点部分分以防爆炸
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back

typedef long long ll;
const int N = 510;
int c, n, m, d, q;
int w[500010];
int k[N];
vector <pair<int, int>> xianlu[500010]; // di tie zhan i de xian lu dou you na xie
ll dis[N][N];

int main () {
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i ++) {
        scanf("%d", w + i);
    } for (int i = 1; i <= n; i ++) {
        scanf("%d", k + i);
        for (int j = 1; j <= k[i]; j ++) {
            int x, y;
            scanf("%d%d", &x, &y);
            xianlu[x].pb ({i, y});
        }
    } 
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            dis[i][j] = 1145141919810810810;
        }
    } for (int i = 1; i <= m; i ++) {
        int _ = xianlu[i].size();
        for (int j = 0; j < _; j ++) {
            for (int k = 0; k < j; k ++) {
                // printf("[%d %d %d %d %d %d %d]\n", i, j, k, xianlu[i][j].se, xianlu[i][k].se, xianlu[i][j].fi, xianlu[i][k].fi);
                dis[xianlu[i][j].fi][xianlu[i][k].fi] = dis[xianlu[i][k].fi][xianlu[i][j].fi] = min (dis[xianlu[i][j].fi][xianlu[i][k].fi], 1ll * xianlu[i][j].se + xianlu[i][k].se);
            }
        }
    } for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j) {dis[i][j] = 0; continue;}
            for (int k = 1; k <= n; k ++) {
                dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    } 
    
    for (int i = 1; i <= q; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ll ans = 1145141919810810810;
        int _ = xianlu[x].size();
        int __ = xianlu[y].size();
        for (int j = 0; j < _; j ++) {
            for (int k = 0; k < __; k ++) {
                ans = min (ans, 1ll * w[x] + w[y] + xianlu[x][j].se + xianlu[y][k].se + dis[xianlu[x][j].fi][xianlu[y][k].fi]);
            }
        } printf("%lld\n", ans);
    }
    return 0;
}