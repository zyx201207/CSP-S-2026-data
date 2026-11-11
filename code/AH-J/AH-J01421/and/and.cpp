#include<bits/stdc++.h>
using namespace std;

int main() {

   freopen("and.in" ,"r", stdin);
   freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if(m == 1) {
        long long maxn = -1;
        for(int i = 0; i < n; ++i) {
            maxn = max(maxn, a[i]);
        }

        cout << maxn << '\n';
        return 0;
    }

    if(m == 2) {
        long long maxn = -1;
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                maxn = max(maxn, a[i] & a[j]);
            }
        }

        cout << maxn << '\n';
        return 0;
    }

    if(m == n) {
        long long ans = a[0];
        for(int i = 1; i < n; ++i) {
            ans = ans & a[i];
        }

        cout << ans << '\n';
        return 0;
    }

    sort(a, a + n);

    long long ans = a[n - 1];
    for(int i = n - 2; i >= n - m; --i) {
        ans = ans & a[i];
    }

    cout << ans << '\n';

    return 0;
}
