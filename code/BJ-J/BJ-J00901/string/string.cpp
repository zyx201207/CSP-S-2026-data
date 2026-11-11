#include <iostream>
using namespace std;
#define int long long
int a[200010];
char c[200010];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i] >> c[i];
    int l = 1, r = n, cntl = a[1], cntr = a[n], cl = c[1], cr = c[n];
    int ans = 0;
    while(l < r) {
        if(cntl < cntr) {
            if(cl == cr) {
                cntr -= cntl;
                l++;
                cntl = a[l], cl = c[l];
            }
            else {
                ans += cntl;
                cntr -= cntl;
                l++;
                cntl = a[l], cl = c[l];
            }
        }
        else if(cntl > cntr) {
            if(cl == cr) {
                cntl -= cntr;
                r--;
                cntr = a[r], cr = c[r];
            }
            else {
                ans += cntr;
                cntl -= cntr;
                r--;
                cntr = a[r], cr = c[r];
            }
        }
        else {
            if(cl == cr) {
                l++, r--;
                cntl = a[l], cl = c[l];
                cntr = a[r], cr = c[r];
            }
            else {
                ans += cntl;
                l++, r--;
                cntl = a[l], cl = c[l];
                cntr = a[r], cr = c[r];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
