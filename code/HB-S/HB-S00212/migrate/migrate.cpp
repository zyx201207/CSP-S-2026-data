#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;

int a[N];
bool sp = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i >= 2 && a[i]-a[i-1] != a[2] - a[1]) sp = false;
        }
        if (sp) {
            int w = a[2] - a[1];
            if (d <= w * 2 || d >= (a[n]-a[1])) {cout << "0\n"; continue;}
            long long ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i=1; j <= n; j++) if ((a[j]-a[i]+w)%d == 0) ans++;
            }
            cout << ans;
            return 0;
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}