#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
long long m;
int ans;
long long a[N];
long long s[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1, a+n+1);

    if (a[1] == a[n]) {
        cout << n <<endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i+1; j--) {
            if (a[j]-a[i] > m) continue;
            if (((s[j] - s[i-1] + m)/(j-i+1)) >= a[j]) {
                ans = max(ans, j-i+1);
                break;
            }
        }
    }

    cout << ans <<endl;

    return 0;
}
