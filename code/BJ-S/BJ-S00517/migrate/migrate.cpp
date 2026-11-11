#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int n, d, x[2000005], sq[2000005], tmp;
int lst;
// inline int dudu(int l)
// {
//     lst = l;
//     int cur = upper_bound(x + l, x + n + 1, x[l] + d) - x - 1;
//     if (cur == lst)
//     {
//         continue;
//     }
//     tmp = 0;
//     while (1)
//     {
//         while (cur == lst + 1 && cur <= n)
//         {
//             lst++;
//             cur = upper_bound(x + cur, x + n + 1, x[cur] + d) - x - 1;
//         }
//         if (cur == lst)
//         {
//             tmp = 1;
//             break;
//         }
//         if (cur >= n)
//         {
//             tmp = 2;
//             break;
//         }
//         //int A = cur - 1;
//         if (x[cur + 1] - x[cur - 1] > d)
//         {
//             lst = cur;
//             cur = upper_bound(x + lst, x + n + 1, x[lst] + d) - x - 1;
//             continue;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return cur;
// }
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld %lld", &c, &t);
    while (t--)
    {
        scanf("%lld %lld", &n, &d);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", x + i);
            // sq[i] = sq[i - 1];
            // if (x[i] - x[i - 2] <= d)
            //     sq[i]++;
        }
            int g = x[2] - x[1], ans = 0;
            if (g * 2 <= d)
            {
            long double a = 1.0 * d / g;
            int aa = a;
            ans = n - aa * 2 + 1;
            }
            printf("%lld\n", max(0ll, ans));
        // int ans = 0, rem = 0;
        // for (int l = 1; l <= n - 3; l++)
        // {
        //     int A = rem;
        //     rem = 0;
        //     int cur = dudu(l);
        //     if (tmp == 1)
        //     {
        //         l = cur;
        //         continue;
        //     }
        //     else if (tmp == 2)
        //         break;
        //     if (x[cur - 2] + d >= x[cur + 1])
        //     {
        //         l = lst;
        //         continue;
        //     }
        //     A += (lst - l + 1);
        //     int r = cur + 1;
        //     int nxt = dudu(r);
        //     // R - cur = B
        //     if (tmp == 1)
        //     {
        //         r = nxt;
        //         l = nxt;
        //     }
        //     else if (tmp == 2)
        //     {
        //         r = n;
        //         l = n;
        //     }
        //     else if (tmp == 0)
        //     {
        //         r = 
        //     }
        // }
    }
    return 0;
}
//A B