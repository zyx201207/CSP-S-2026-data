#include <bits/stdc++.h>
#define int long long
int a[500010];
int s[500010];
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,m,ans = 0;
    std::cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        std::cin>>a[i];
    }
    std::sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        s[i] = s[i-1] + a[i];
    }
    for(int i = 1;i <= n;i++) {
        int l = 1,r = i;
        for(;l < r;) {
            int mid = l+r>>1;
            if((i-mid+1)*a[i] - s[i] + s[mid-1] > m) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        ans = std::max(ans,i-l+1);
    }
    std::cout<<ans;
}
