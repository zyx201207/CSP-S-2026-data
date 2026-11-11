#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m;
ll a[N], s[N], s2[N];
int ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)  cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)  s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        while (a[i] == a[i + 1])  i++;
        if (i * a[i] - s[i] <= m) {
            ans = max(ans, i);
            continue;
        }
        int l = 1, r = i - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (i * a[i] - s[i] - mid * a[i] + s[mid] <= m)  r = mid;
            else  l = mid + 1;
        }
        ans = max(ans, i - l);
    }
    cout << ans;
    return 0;
}