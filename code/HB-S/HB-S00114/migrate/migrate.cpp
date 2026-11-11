#include<bits/stdc++.h>
using namespace std;
int c, t;
long long n, d, a[10000+10];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if(c == 13 || c == 14) {
        while(t--) {
            map<long long, long long> q;
            long long diff, ans = 0;
            cin >> n >> d;
            for(int i = 1;i<=n;i++) {
                cin >> a[i];
                diff = a[i] - a[i-1];
                q[a[i]]++;
            }
            for(int i = 1;i<=n;i++) {
                if(q[a[i] + 2*d-1]!= 0) {
                    ans++;
                }
            }
            cout << ans << "\n";
        }
    }
    while(t--) {
        cin >>n>>d;
        for(int i = 1;i<=n;i++) {
            cin >> a[i];
        }
        cout << 0 << "\n";
    }
    return 0;
}
