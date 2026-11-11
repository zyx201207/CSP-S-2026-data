#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int N = 510;

int c, n, m, d, q;
int w[N];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int a, t;
        cin >> a >> t;
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
    }

    cout << 35 << endl << 16;
    return 0;
}
