#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main()
{
#ifndef QWQ
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
#endif
    cin.tie(0)->sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; ++i)
    {
        s[i] = s[i - 1] + a[i];
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i < n && a[i + 1] == a[i])
        {
            continue;
        }
        int l = 1, r = i, res = r;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // cerr << i << ' ' << mid << ' ' << s[i] - s[mid - 1] << ' ' << (i - mid + 1) * a[i] << '\n';
            if (s[i] - s[mid - 1] + m >= (i - mid + 1) * a[i])
            {
                res = mid, r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans = max(ans, i - res + 1);
        // cerr << i << ' ' << res << '\n';
    }
    cout << ans << '\n';

    return 0;
}
/*
5 5
1 2 4 8 9

14:58 finish bisearch but WA
15:02 OK
15:05 finish pai, goto T2
*/
/*
通读题目到 15:00

T1: 排序二分前缀和

T2: 题目理清了，线路少，站多，有度数限制且极小，很明显有并查集

T3：要带 log，可以考虑先打个暴力

T4：比较猎奇，等会细看

18:17 vmware 全部过编和检验

此时 100+100+32+45

18：23

现在尘埃已经落定，我也没什么好打的了，没有辜负这几年来的付出一切都是值得的。

我要上厕所！！！
我要上厕所！！！
我要上厕所！！！
我要上厕所！！！
我要上厕所！！！

祝大家一发入魂！！！迎娶塔露拉！！！

*/