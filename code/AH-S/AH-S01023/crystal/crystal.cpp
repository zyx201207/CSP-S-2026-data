#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;
int n; ll m;
ll a[N],b[N];

bool chk(int k) {   
    for(int i=k+1;i<=n;++i) if(a[i]*k-(b[i-1]-b[i-k-1])<=m) return true;
    return false;
}

void wk() {
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) b[i]=b[i-1]+a[i];
    int l=1,r=n-1,mid,ok=0;
    for(;l<=r;) {
        mid=(l+r)>>1;
        if(chk(mid)) ok=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ok+1);
}

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    wk();

    return 0;
}