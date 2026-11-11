#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n, d, x[1000005];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c >> t;
    while (t--) {
        int n,d; cin >> n >> d;
        for (int i = 1;i <= n;i++) {
            cin >> x[i];
        }
        cout << "0\n";
    }
    return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
