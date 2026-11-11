#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], b[500005], ans, cnt, t, t1;
bool flag = false;
bool cmp(long long x, long long y) {
    return x > y;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    for(int i = 1;i < n;i++) {
        if(a[i] = a[i + 1] - 1)
            flag = true;
        else
            flag = false;
    }
    if(flag == true) {
        for(int i = 1;i < n;i++) {
            if(m - i >= 0) {
                m -= i;
                ans++;
            }
        }
        cout << ans+1;
        return 0;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, cmp);
    if(n % 2 != 0) {
        for(int i = (n + 1) / 2 - 1;i >= 1;i--) {
            if(m - (a[(n + 1) / 2] - a[i]) >= 0) {
                t = a[(n + 1) / 2];
                ans++;
                m -= a[(n + 1) / 2] - a[i];
            }
        }
        for(int i = 1;i <= n;i++) {
            if(a[i] == t)
                ans++;
        }

        for(int i = (n + 1) / 2 - 1;i >= 1;i--) {
            if(m - (a[i] - a[(n + 1) / 2]) >= 0) {
                t1 = a[(n + 1) / 2];
                cnt++;
                m -= a[i] - a[(n + 1) / 2];
            }
        }
        for(int i = 1;i <= n;i++) {
            if(a[i] == t)
                cnt++;
        }
    }
    else if(n % 2 == 0) {
        for(int i = n / 2 - 1;i >= 1;i--) {
            if(m - (a[n / 2] - a[i]) >= 0) {
                t = a[n / 2];
                ans++;
                m -= a[n / 2] - a[i];
            }
        }
        for(int i = 1;i <= n;i++) {
            if(a[i] == t)
                ans++;
        }

        for(int i = n / 2 - 1;i >= 1;i--) {
            if(m - (a[i] - a[n / 2]) >= 0) {
                t1 = a[n / 2];
                cnt++;
                m -= a[i] - a[n / 2];
            }
        }
        for(int i = 1;i <= n;i++) {
            if(a[i] == t)
                cnt++;
        }
    }
    cout << max(cnt, ans);
    return 0;
}
