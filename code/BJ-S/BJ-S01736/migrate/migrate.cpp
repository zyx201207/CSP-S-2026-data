#include <bits/stdc++.h>
using namespace std;
int c, T;
int a[1234567];
int main() {


    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> T;
    while(T--) {
        int n, d;
        cin >> n >> d;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(d >= a[n] - a[1]) {
            cout << "0" << endl;
        }
        else {
            cout << n - 3 << endl;
        }
    }

    return 0;
}
