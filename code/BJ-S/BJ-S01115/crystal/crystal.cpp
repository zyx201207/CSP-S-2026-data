#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m; cin >> n >>m;
    for (int i = 1; i <= n; i++) cin >>a[i];
    sort(a+1,a+1+n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1]+a[i];
    long long ans = 0;
    for (int i = n; i >= 1; i--){
        long long l=1,r=i,max_ = 0;
        while (l <= r){
            long long mid = (l+r)/2;
            long long have = i-mid+1;
            long long need= a[i]*have-(sum[i]-sum[mid-1]);
            if (need <= m) max_ = have,r = mid-1;
            else l = mid+1;
        }
        ans = max(ans,max_);
    }
    cout << ans;
    return 0;
}
