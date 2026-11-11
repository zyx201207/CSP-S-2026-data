#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n,m,a[N],ans,sum[N];
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++) {
        int l=1,r=i,mid,nans=0;
        while(l<=r) {
            mid=l+r>>1;
            if((mid-1)*a[i]-(sum[i-1]-sum[i-mid])<=m) {
                l=mid+1;
                nans=max(nans,mid);
            } else r=mid-1;
        }
        ans=max(ans,nans);
    }
    cout<<ans;
    return 0;
}