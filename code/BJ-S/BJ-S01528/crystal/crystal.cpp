#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5*1e5+5;
int n,m,a[N],ans = 1,tmp;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + 1 + n);
    a[0] = 0;
    for (int i = 1;i < n;i++) {
        int s = 0,tmp = 0;
        for (int j = i;j <= n;j++) {
            s += (a[j] - a[j - 1]) * (j - i);
            if (s <= m) tmp++;
        }
        ans = max(ans,tmp);
    }
    cout << ans;
    return 0;
}