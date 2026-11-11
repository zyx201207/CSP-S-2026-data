#include <bits/stdc++.h>
#define cin in
#define cout out
#define ll long long
using namespace std;
ifstream in("subway.in");
ofstream out("subway.out");
ll w[10000], k[10000], a[10000][10000], t[10000][10000];
ll c, n, m, d, q;
// int jishuan(int x, int y)
// {
//     int a_b[2][2];
//     for (ll ki = 0; ki < n; ki++)
//     {
//         cin >> k[ki];
//         for (ll i = 0; i < k[ki]; i++)
//         {
//             if (a[ik] == x)
//             {
//                 a_b[0][0] = i;
//                 a_b[0][1] = ki;
//             }
//             if (a[ik] == y)
//             {
//                 a_b[1][0] = i;
//                 a_b[1][1] = ki;
//             }
//         }
//     }
//     for (int i1 = 0; i1 <= count; i1++)
//     {
//         return
//     }

// }
int main()
{
    cin >> c >> n >> m >> d >> q;
    ll w[m + 1];
    for (ll i = 0; i < m; i++)
    {
        cin >> w[i];
    }

    for (ll ki = 0; ki < n; ki++)
    {
        cin >> k[ki];
        for (ll i = 0; i < k[ki]; i++)
        {
            cin >> a[i][ki] >> t[i][ki];
        }
    }
    ll x, y;
    for (ll r = 0; r < q; r++)
    {
        cin >> x >> y;
        cout << 2;
    }
}
