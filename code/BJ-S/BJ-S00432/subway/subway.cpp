#include <bits/stdc++.h>
# define pir pair <ll, ll>
using namespace std;
typedef long long ll;
const int N = 505, M = 5e5 + 5;
ll c, n, m, d, q;
ll w[M];
ll ans, dis[N][N];
vector <pir> v[M];
// priority_queue <pir, vector <pir>, greater <pir> > pq;
int main ()
{
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++)
        cin >> w[i];
    for (int i = 1; i <= n; i ++)
    {
        ll k;
        cin >> k;
        for (int j = 1; j <= k; j ++)
        {
            ll a, t;
            cin >> a >> t;
            v[a].push_back ({(ll)i, t});
        }
    }
    memset (dis, 127, sizeof (dis));
    ll INF = dis[0][0];
    for (int i = 1; i <= n; i ++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i ++)
    {
        for (int j = 0; j < v[i].size (); j ++)
            for (int k = j + 1; k < v[i].size (); k ++)
            {
                ll x = v[i][j].first, y = v[i][k].first;
                ll wx = v[i][j].second, wy = v[i][k].second;
                dis[x][y] = min (dis[x][y], wx + wy);
                dis[y][x] = min (dis[y][x], wx + wy);
            }
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            for (int k = 1; k <= n; k ++)
            {
                if (dis[i][k] == INF || dis[k][j] == INF) continue;
                dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
                // dis[j][i] = min (dis[j][i], dis[i][k] + dis[k][j]);
            }
    while (q --)
    {
        ll x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << 0 << '\n';
            continue;
        }
        ans = w[x] + w[y];
        ll mn = INF;
        for (pir it1 : v[x])
        {
            for (pir it2 : v[y])
            {
                ll tmp = it1.second + it2.second;
                tmp += dis[it1.first][it2.first];
                mn = min (mn, tmp);
            }
        }
        cout << ans + mn << '\n';
    }
    return 0;
}
/*
从站台走到站厅，让后再走到另一个站台
分为两种：直接在地铁线路上的，和走到站厅的
直接在地铁线路上的：代价为 0
走到站厅的：代价为 t
然后 dij
时间复杂度为 O (qm) 会炸
可以发现：n <= 500 很小
说明可以用 O(nq) 来做，但我貌似不会
O(mn) + O(nq) ？有思路但不太会？
算法：
预处理 dis[i][j] 表示第 i 个点第一次到达第 j 条线路需要多久
怎么预处理呢？
注意到：保证图连通 所有的 k[i] 相加不超过 5e5
我刚刚似乎没看懂题，来重新捋一下思路
dis[i][j] 表示从第 i 条线路到第 j 条线路需要多久
枚举换乘点 O(n ^ 3 + md + qn) 理论时间复杂度能AC
样例全 AC 了 gg
大样例 + O2 
最高0.62s
GG
八十中电脑无敌了 viscode 在左边时屏幕变暗，在右边时重新变亮
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
g++ 2.cpp -o 1
./1
diff -q -b -B subway.out subway7.ans
10000000000
*/