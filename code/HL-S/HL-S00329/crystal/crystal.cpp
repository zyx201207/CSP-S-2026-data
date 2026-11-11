#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int a[500010],q[500010];

void solve() {
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
    int ans=0;
    //for (int i=1;i<=n;i++) cout<<q[i]<<' ';
    //cout<<endl;
    for (int l=1,r=1;r<=n&&l<=r;r++) {
        if ((a[r]*(r-l+1))>((q[r]-q[l-1])+m)) {
            //cout<<ans<<' '<<l<<' '<<r<<endl;
            ans=max(ans,r-l);
            l++;
            if ((a[n]*(n-l+1))<=((q[n]-q[l-1])+m)) {
                //cout<<l<<' '<<a[n]<<' '<<q[n]<<' '<<q[l-1]<<endl;
                cout<<n-l+1;
                return;
            }
        }
    }
    cout<<ans;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
    return 0;
}
