#include <bits/stdc++.h>
#define int long long
const int N=5e5+5;
using namespace std;
int n,m,a[N],ans,m1,dt,l,r,ans1;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    l=1,r=1;
    ans=1;m1=m;
    while (r<n) {
        r++;ans++;
        dt=a[r]-a[r-1];
        m1-=(ans-1)*dt;
        while (m1<0 && l<=r){
            m1+=a[r]-a[l];
            l++;ans--;
        }
        //cout<<l<<" "<<r<<" "<<ans<<endl;
        ans1=max(ans1,ans);
    }
    cout<<ans1;

    return 0;
}
