#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
int n, m;
ll a[N], b[N], cnt[N], ans[N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll l = 0;
    for (int k = 1; k <= n; k++) {
        l++;
        for (int i = l; i <= n; i++) {
            b[i] = a[i];
            cnt[b[i]]++;
        }
        int cnt1 = 0, lft = 0, rgh = 0;
        for (int i = l; i <= n; i++) {
            if (cnt[b[i]] > 1) {
                for (int j = l; j <= n; j++) {
                    if (j == cnt[b[i]]) {
                        cnt1++;
                    }
                }
                for (int j = l; j <= n; j++) {
                    if (j == cnt[b[i]] && cnt1 == 1) {
                        lft = j;
                    }
                    if (j == cnt[b[i]] && cnt1 > 1) {
                        rgh = j;
                    }
                }
                for (int j = lft; j < rgh; j++) {
                    b[j] = rgh + j - 1;
                }
            }
        }
        for (int i = l; i <= n; i++) {
            ans[b[i]]++;
            cnt[b[i]] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
