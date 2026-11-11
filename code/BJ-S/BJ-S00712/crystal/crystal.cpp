// 14.31 14.35
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;

int n, ans; ll m;
ll a[N], s[N];

int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);

    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    for(int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(a[i] * mid - (s[i] - s[i - mid]) <= m) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, l);
    }
    cout << ans << '\n';

    return 0;
}