#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n;
typedef long long ll;
ll m,a[maxn],s[maxn];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w".stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll ans=0;
    for(int i=1;i<=n;i++) {
        ll l=1,r=i,k=1;
        while(l<=r) {
            int mid=l+r>>1;
            if(s[i]+m >= a[i]*mid+s[i-mid]) k=mid,l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,k);
    }
    cout<<ans;
    return 0;
}
