/*
[01:31]OK!看第二题辣

[01:47]感觉好难？先从简单的kruscal入手把
哦不对不对，由于有多个出行计划，好像得用prim，O(n^3)???

[01:49]突然发现题目输入竟然给了测试点编号？干什么用的，难不成用来骗分？

[02:04~02:09]怎么两个小时了？！
想到一个方法，先写一下：
将整条路线看作一个节点，每个地铁站的站厅看作节点，将站厅到站台的距离视为该地铁站节点到地铁路线的距离，作prim，节点数为m+d，O(m^3)好像还是不够，但能够过前8个样例
32pts也是分，开写！

[02:25]把n看成d了……不过无伤大雅，前32pts还是能拿到（应该把）

[02:41]prim写完了，感觉还行，甚至用不上parent记录路径

[02:55]编译错误，排了半天发现是数组开大了……尝试优化
kruskal是单点到任意一点的最短路，最大O(edge)，即O(n*d)，对于q次询问，即使不优化时间复杂度也小于O(m^3),约在10^9量级，我们还可以集中回答相同起始点的询问，节省空间时间

[03:30]哦不不不还有半个小时就交卷了，死手快写

[03:34]写完了，稍微验证再调一下就行，后两题稍稍骗个分

[03:36]哦不，遇到死循环了

[03:39]这个1912是何意为……

[03:54]除了超时的，基本都能过，不管了。
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 500505; // > 5e5+500
const int N = 10005;
int c, n, m, d, q, k, a, t, cnt=1;
int weight[M], head[M], to[N], nxt[N], we[N];
long long len[M];
bool flag[M];
struct Q {
    int x, y, ind, ans;
} qs[100005];
bool cmp1(Q x, Q y) {
    return x.x < y.x;
}
bool cmp2(Q x, Q y) {
    return x.ind < y.ind;
}
void create(int u, int v, int w) {
    we[cnt] = w;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}
void kruskal(int node) {
    //cout << node << '\n';
    memset(len, -1, sizeof len);
    memset(flag, false, sizeof flag);
    len[node] = 0;
    int nd = node, minlen=0;
    while (minlen != -1) {
        // printf("node=%d\n", nd);
        int edge = head[nd];
        flag[nd] = true;
        while (edge) {
            int newlen = len[nd]+we[edge];
            if(!flag[to[edge]] && (len[to[edge]] == -1 || newlen < len[to[edge]])) len[to[edge]] = newlen;
            // printf("to=%d, w=%d, len=%lld\n", to[edge], we[edge], len[to[edge]]);
            edge = nxt[edge];
        }
        minlen = -1;
        for (int i = 1; i <= m+n; i++) {
            if (!flag[i] && len[i]!=-1){
                if (len[i] < minlen || minlen == -1){
                    minlen = len[i];
                    nd = i;
                }
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

    // 规定节点i(1<=i<=m)表示第i个地铁站，节点m+i(1<=i<=n)表示第i条线路
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> weight[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a >> t;
            // 链式前向星吧，毕竟边比较少
            create(m+i, a, t);
            create(a, m+i, t);
        }
    }
    // for (int i = 1; i <= m+n; i++) {
    //     len[i][i] = 0;
    //     parent[i][i] = i;
    // }
    // for (int mid = 1; mid <= m+n; mid++) {
    //     for (int i = 1; i <= m+n; i++) {
    //         for (int j = 1; j <= m+n; j++) {
    //             if (i==mid || j==mid || i==j) continue;
    //             // 处理 i->mid->j
    //             int la = len[i][mid], lb = len[mid][j];
    //             if (la && lb && ((!len[i][j]) || (la+lb < len[i][j]))) {
    //                 len[i][j] = la+lb;
    //             }
    //         }
    //     }
    // }
    for (int i = 0; i < q; i++) {
        cin >> qs[i].x >> qs[i].y;
        qs[i].ind = i;
    }
    sort(qs, qs+q, cmp1);
    int last = -1;
    for (int i = 0; i < q; i++) {
        if (qs[i].x != last) kruskal(qs[i].x);
        qs[i].ans = len[qs[i].y]+weight[qs[i].x]+weight[qs[i].y];
        last = qs[i].x;
    }
    sort(qs, qs+q, cmp2);
    for (int i = 0; i < q; i++) {
        cout << qs[i].ans << '\n';
    }
	return 0;
}
