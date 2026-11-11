# include <bits/stdc++.h>
using namespace std;
long long n, m, a[200001], ans, b[200001];
bool cmp(long long x, long long y) {
    return x > y;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    if(m == 2) {
        for(int i = 1;i <= n;i++) {
            for(int j = i + 1;j <= n;j++)
                ans= max(ans, a[i] & a[j]);
        }
        cout << ans;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1;i < m;i++)
        ans = a[i] & a[i + 1];
    cout << ans;
    return 0;
}
