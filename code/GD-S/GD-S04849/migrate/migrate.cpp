#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main()
{
#ifndef QWQ
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
#endif
    cin.tie(0)->sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10);

    int c, T;
    cin >> c >> T;
    while (T--)
    {
        int n, d, gc = -1;
        cin >> n >> d;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (i > 1)
            {
                if (gc == -1)
                {
                    gc = a[i] - a[i - 1];
                }
                else if (gc != a[i] - a[i - 1])
                {
                    gc = -2;
                }
            }
        }
        vector<int> l(n + 1), r(n + 1);
        for (int i = 1, j = 1; i <= n; ++i)
        {
            while (j <= n && a[j] - a[i] <= d)
            {
                ++j;
            }
            r[i] = j - 1;
        }
        for (int i = n, j = n; i; --i)
        {
            while (j && a[i] - a[j] <= d)
            {
                --j;
            }
            l[i] = j + 1;
        }
        if (r[1] == n)
        {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            vector<int> dis(n + 1, n), f(n + 1, 0);
            dis[i] = 0, f[i] = 1;
            for (int j = i; j <= n; ++j)
            {
                if (!f[j])
                {
                    break;
                }
                if (f[j] == 2)
                {
                    ++ans;
                }
                if (f[j] > 2)
                {
                    f[j] = 3;
                }
                int k = j + 1;
                for (int len = 1 << __lg(r[i] - i + 1); len; len >>= 1)
                {
                    if (k + len <= n && dis[k + len] == dis[j])
                    {
                        k += len;
                    }
                }
                for (; k <= r[j]; ++k)
                {
                    if (dis[j] + 1 < dis[k])
                    {
                        dis[k] = dis[j] + 1;
                        f[k] = f[j];
                    }
                    else if (dis[j] + 1 == dis[k])
                    {
                        f[k] += f[j];
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    cerr << clock() << '\n';

    return 0;
}
/*
15:49 start
16:18 O(n) WA
16:25 O(n) jia le jian copy
16:35 WC & finish bruce
16:43 24 pts
*/
/*
T3：要单 log，可以考虑先打个暴力

先想 20min，如果不会先暴力然后拼包先，to 16：12

极短点对，先 check 一下，10 min to 16：12

猜了一个最多研究到 16:40，有点假不是这么做的，先上厕所！！

先打一下暴力吧，预估 20 min to 16：47

效率有点低，让我先快速拼包，拼到 17：10

有点卡了，跳！！！

*/