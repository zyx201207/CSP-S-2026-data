#include <bits/stdc++.h>
using namespace std;

int n, i, ans = 1;
long long m;
long long a[500007], b[500007];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for (i = 1; i <= n; i++)  b[i] = a[i] + b[i-1];
    for (i = 2; i <= n; i++) {
        while(ans*a[i] - (b[i-1] - b[i-1-ans]) <= m && i-1-ans >= 0) ans++;
    }
    cout << ans << endl;
    return 0;
}