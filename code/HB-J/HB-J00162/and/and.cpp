#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[200001];

int main() {
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    scanf ("%lld%lld",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf ("%lld",&a[i]);
    }
    if (m==1) {
        sort (a+1,a+n+1);
        printf ("%d",a[n]);
        return 0;
    }
    if (m==2) {
        ll ans=0;
        for (int i=1;i<n;i++) {
            for (int j=i+1;j<=n;j++) {
                ans=max(ans,a[i]&a[j]);
            }
        }
        printf ("%d",ans);
        return 0;
    }
    if (m==n) {
        ll ans=a[1];
        for (int i=2;i<=n;i++) {
            ans=ans&a[i];
        }
        printf ("%d",ans);
    }
    return 0;
}
