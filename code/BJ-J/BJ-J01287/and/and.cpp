#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m, a[maxn];
int solve() {
    int x = 0;
    for(int i = 30; i >= 0; i--) {
        int y = x + (1 << i);
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            cnt += (a[i] & y) == y;
        }
        if(cnt >= m) x = y;
    }
    return x;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << solve() << "\n";
    return 0;
}