// GZ-S00414 贵州省都匀第一中学 张铮瀚
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define ull long long
#define int long long

#define maxn 500007
int a[maxn];
int d[maxn], rsumd[maxn];
int n,m;

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i<=n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i<=n; ++i) d[i] = a[i] - a[i - 1];
    d[1] = 0;

    int sum = 0ll;
    for(int i = n - 1; i >=1; --i) 
        rsumd[i] = rsumd[i + 1] + d[i + 1], sum += rsumd[i];
    
    if(sum <= m) {
        cout << n << endl;
        return 0;
    }
    int ans = 0;
    for(int r = n; r >= 1; --r) {
        sum -= (rsumd[r] - rsumd[r + 1]) * r;
        int cur = sum;
        for(int l = 1; l <= r; ++l) {
            if(r - l + 1 <= ans) break;
            if(cur <= m) {
                ans = max(ans, r - l + 1);
            }
            cur -= rsumd[l] - rsumd[r];
        }
    }
    cout << ans << endl;
    return 0;
}