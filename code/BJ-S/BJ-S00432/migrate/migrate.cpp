#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll c, t;
ll n, d;
ll x[N], a[N], cnt, nxt[N];
bool gt2 ()
{
    ll sum = 0;
    for (int i = 2; i <= cnt; i ++) 
    {
        a[i] --;
        if (a[i] <= a[i - 1])
        {
            a[i] ++;
            continue;
        }
        if (nxt[a[i]] >= a[i + 1]) return 1;
        a[i] ++;
    }
    return 0;
}
bool gt ()
{
    bool flag = 0;
    for (int i = 2; i <= cnt; i ++) 
    {
        a[i] --;
        if (a[i] <= a[i - 1])
        {
            a[i] ++;
            continue;
        }
        if (nxt[a[i]] >= a[i + 1])
        {
            if (flag) {a[i] ++; return 0;}
            flag = 1;
            if (gt2 ()) {a[i] ++; return 0;}
        }
        a[i] ++;
    }
    return flag;
}
int main ()
{
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t --)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i ++) 
            cin >> x[i];
        if (c == 11 || c == 12)
        {
            ll mx = 0;
            for (int i = 1; i <= n; i ++)
            {
                if (abs (x[i] - x[1]) <= d) mx = i - 1;
                else break;
            }
            if (mx <= 1) cout << 0 << '\n';
            else
            {
                ll tmp = mx + mx - 1;
                cout << max(n - tmp, 0LL) << '\n';
            }
            continue;
        }
        ll r = 1;
        for (int l = 1; l <= n; l ++)
        {
            while (r <= n && x[r] - x[l] <= d) r ++;
            if (r > n || abs(x[r] - x[l]) > d) r --;
            nxt[l] = r;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = i + 1; j <= n; j ++)
            {
                ll now = i;
                bool flag = 0;
                cnt = 0;
                while (now < j)
                {
                    if (nxt[now] == now)
                    {
                        flag = 1;
                        break;
                    }
                    a[++ cnt] = now;
                    now = nxt[now];
                };
                if (flag) continue;
                // if (i == 5 && j == 8) cout << "ok \n";
                a[cnt + 1] = j;
                if (gt ()) ans ++;
            }
        cout << ans << '\n';
    }
    return 0;
}
/*
这道题很神秘，题面要求恰好有两条最短路径。
感觉可以用 dp 来做？
不是这次题目杂这么简单 2h 就 AC 了两题
现在 T3 都有点思路了，糖糖？
因为有两条最短路径，所以可一先兆其中一条最短路经
从 u 开始，每次尽可能往后跳，直到跳到 v 点
然后找第二条路经，可以发现，若恰好存在两条最短路径
那么第二条路经必然是把第一条路径改变一个点后形成的
而且不能存在第三条合法路径，而且第三条路经不一定是由第一条路径改变一个点后形成的
可能是由第二条路径改变一个点后形成的
从第 i 个点尽可能往后跳两个点的编号为 jp[i]
若jp[jp[i]] = jp[jp[i] - 1]，我门便称这个点为转折点
若jp[jp[i]] = jp[jp[i] - 2]，我门便称这个点为二转点
最终答案 = 所有存在第二条路径且不存在第三条路径的路径数量
存在第二条路径 = 有转折点
存在第三条路径 = 不知道
好的，我成成成功功功的不会了
来写部分分
24 分暴力：O(n ^ 3) 枚举 u, v
0 1
8 3
0 1 2 4 8 10 11 13
*/