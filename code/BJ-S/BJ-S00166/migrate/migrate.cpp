#include<bits/stdc++.h>
using namespace std;

int c, t;
long long a[2000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t --) {
        long long n, d; cin >> n >> d;
        for(int i = 1;i <= n;i ++) {
            cin >> a[i];
        }
        int x = a[1], i;
        for(i = 1;i <= n;i ++) {
            if(x + d < a[i]) {
                break;
            }
            if(x < a[i]) {
                x += d;
            }
        }
        if(i != n) {
            n = i - 1;
        }
        int ans = 0;
        for(int i = 2;i <= n;i ++) {
            for(int j = 1;j <= i;j ++) {
                int x = abs(a[i] - a[j]);
                if(x % 2 == 1 && x != 1) {
                    ans ++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
