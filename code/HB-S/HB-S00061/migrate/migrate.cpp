#include <bits/stdc++.h>
using namespace std;
long long c, t, cnt, n, d, x[2000001];
bool flag = true, b = true;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for(int i = 1;i <= t;i++) {
        cin >> n >> d;
        for(int j = 1;j <= n;j++) {
            cin >> x[j];
        }
        for(int j = 1;j < n;j++) {
            if(x[j + 1] - x[j] == 1)
                flag = false;
            if(x[j + 1] - x[j] > d)
                b = false;
        }
        /*
        for(int j = n;j >= 4;j--) {
            if(x[j] - x[j-d-1] > d) {
                cnt++;
            }
        }*/
        if(b == false) {
            cout << 0 << endl;
            continue;
        }
        if(flag = true) {
            cout << n - d - 1<< endl;
        }
        //cnt = 0;
    }
    return 0;
}
