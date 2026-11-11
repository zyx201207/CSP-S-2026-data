

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll s[500009], num[500009];
ll maxn = -2e9;
ll n, m;

int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &num[i]);
    }
    sort(num + 1, num + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + num[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l < r) {
            int mid = l + r >> 1;
            ll opt = num[i] * (i - mid + 1) - (s[i] - s[mid - 1]);
            //cout << num[i] * (i - mid + 1) << " " << (s[i] - s[mid - 1]) << endl;
            //cout << i << " " << mid << " " << opt << endl;
            /*if (opt == m) {
                maxn = max(maxn, 1LL * (i - mid + 1));
                break;
            }*/
            if (opt > m) {
                l = mid + 1;
            }else{
                //cout << mid << " " << i << " " << opt << endl;
                r = mid;
                //cout << i << " " << 
            }
        }
        maxn = max(maxn, 1LL * (i - l + 1));
    }
    cout << maxn << endl;
    return 0;
}