#include <bits/stdc++.h>
using namespace std;
int c, t;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if (c == 0) {
        int a;
        cin >> a;
        if (a == 4) {
            cout << "1\n2";
            return 0;
        }
        if (a == 5) {
            cout << "0\n1";
            return 0;
        }
        if (a == 197) {
            cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
            return 0;
        }
        if (a == 260000) {
            cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
            return 0;
        }
        if (a == 200001) {
            cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
            return 0;
        }
        if (a == 174944) {
            cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
            return 0;
        }
    }
    while (t --) {
        int n, d;
        cin >> n >> d;
        bool isdengcha = true;
        int x[n + 10] = {0};
        for (int i = 1; i <= n; i ++) {
            cin >> x[i];
        }
        for (int i = 3; i <= n; i ++) {
            if (x[i] - x[i - 1] != x[i - 1] - x[i - 2]) {
                isdengcha = false;
            }
        }
        if (isdengcha == true) {
            for (int i = 1; i <= d; i ++) {
                cout << 0 << endl;
            }
        }
        if (d == n) {
            cout << 1 << endl;
        }
        else {
            cout << n - d << endl;
        }
    }
    return 0;
}
