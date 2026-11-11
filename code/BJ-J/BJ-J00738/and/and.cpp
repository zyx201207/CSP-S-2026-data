#include <bits/stdc++.h>
using namespace std;

const int N = 2 *1e5 + 5;;
typedef long long ll;
//int n, m, a[N];
//char c[N];
//ll cnt1[50], cnt2[50], sum[N];
int n, m;
ll f[N], a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[m - 1] = a[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--)
            f[j] = max(f[j], f[j - 1] & a[i]);
    }

    //cout << f[0] << endl;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
    }

    cout << f[m] << endl ;
    return 0;
}
