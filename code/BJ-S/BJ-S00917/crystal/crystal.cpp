#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 5e5 + 7;
int n, ans;
LL m, a[N], s[N];
bool chk(int x, int y) {
    return (0ll + y + 1 - x) * a[y] - s[x] + s[y + 1] <= m;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = n; i >= 1; i--)
        s[i] = s[i + 1] + a[i];
    for(int i = 1; i <= n; i++) {
        int l = 0, r = i + 1;
        while(l + 1 < r) {
            int mid = l + r >> 1;
            if(chk(mid, i)) r = mid;
            else l = mid;
        }
        ans = max(ans, i - r + 1);
    }
    cout << ans << '\n';
    return 0;
}
