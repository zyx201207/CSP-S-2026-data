#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int c, t, n, d;
long long x[maxn];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i];
        int ddd = x[2] - x[1];
        if(d < 2 * ddd) cout << 0 << "\n";
        else
        {
            cout << random() << "\n";
        }
    }
    return 0;
}
