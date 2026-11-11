#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500005], cnt = 1;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    if(n <= 5000) {
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 2; i <= n; i++) {
            ll sum = 1, tmp = m;
            for(int j = i - 1; j >= 1; j--) {
                if(tmp >= a[i] - a[j]) {
                    tmp -= (a[i] - a[j]);
                    sum++;
                }
            }
            cnt = max(cnt, sum);
        }
        cout << cnt << endl;
        return 0;
    } else {
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = n - 1; i >= 1; i--) {
            if(m >= labs(a[n] - a[i])) {
                cnt++;
                m -= labs(a[n] - a[i]);
            }
        }
        cout << cnt << endl;
        return 0;
    }
    return 0;
}