#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+5;
int c, T;
int n;
ll d, x[N];
int p[N], ne[N];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while (T--) {
        memset(p, 0, sizeof(p));
        memset(ne, 0, sizeof(ne));
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        int j = 1;
        for (int i = 1; i <= n; i++) {
            while ((j == i || x[j+1] - x[i] <= d) && j+1 <= n)
                j++;
            if (j == n) {
                if (x[n] - x[i-1] > d) {
                    ne[i] = n;
                    p[n] = i;
                }
                break;
            }
            ne[i] = j;
            p[j] = i;
        }
        if (ne[1] == 0) {
            cout << (n == 3 ? 1 : 0) << endl;
            continue;
        }
        int ans = 0;
        for (int i = n; i; i--) {
            if (ne[i] > i+1 && ne[ne[i]-1] > ne[i])
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
