#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[500005];
map<int, int> mp;

signed main() {
    //freopen("crystal2.in", "r", stdin);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int sum1 = 0, sum2 = 0;
    int tmp1 = 0, tmp2 = 0;
    pair<int, int> last[500005];
    int cur = 0, pre = 0;
    int ans = 0;
    for (auto i : mp) {
        sum1 += tmp1 * (i.first - last[cur].first);
        sum2 += tmp2 * (i.first - last[pre].first);
        tmp1 += i.second;
        while(sum1 - sum2 > m) {
            pre++;
            sum2 += (i.first - last[pre].first) * last[pre].second;
            if (sum1 - sum2 < m) {
                int summ = sum2 - (i.first - last[pre].first) * last[pre].second;
                int tmpp = tmp2 + (sum1 - m) / (i.first - last[pre].first);
                ans = max(ans, tmp1 - tmpp);
                break;
            }
            tmp2 += last[pre].second;
        }
        ans = max(ans, tmp1 - tmp2);
        //cout << sum1 << " " << sum2 << " " << tmp1 << " " << tmp2 << "\n";
        last[++cur] = i;
    }
    cout << ans << "\n";
    return 0;
}
