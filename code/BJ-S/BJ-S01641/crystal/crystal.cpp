#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans,sum[500005];
bool check(int x){
    for (int i = x;i <= n;i++) if (a[i] * x - sum[i] + sum[i - x] <= m) return true;
    return false;
}
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
    int l = 1,r = n;
    while (l <= r){
        int mid = l + r >> 1;
        if (check(mid)){
            l = mid + 1,
            ans = mid;
        }else r = mid - 1;
    }
    cout << ans;
    return 0;
}