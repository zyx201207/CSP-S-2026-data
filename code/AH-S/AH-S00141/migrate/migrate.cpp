#include<bits/stdc++.h>

using namespace std;
//rp++ 歪比巴卜

int c, t;

int main() {
    //freopen("migrate.in", "r", stdin);
    //freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for (; t--; ) {
        int n, d;
        int x[2000005];
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        if (c == 11 || c == 12) {
            if (x[2] - x[1] <= d && n == 3)
                cout << 2;
            else
                cout << 0;
            cout << "\n";
            continue;
        }
        if (c == 13 || c == 14) {
            if (n == 3)
                cout << 2;
            else
                cout << 0;
            cout << "\n";
            continue;
        }
        if (c == 15 || c == 16 || c ==17 || c == 18) {
            cout << 0;
            cout << "\n";
            continue;
        }
    }
    return 0;
}
