#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;

int c, t;
int n, d;
int loc[N];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> t;

    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> loc[i];
        if (d == 1)
        {
            cout << 0 << endl;
            continue;
        }
    }
    return 0;
}
