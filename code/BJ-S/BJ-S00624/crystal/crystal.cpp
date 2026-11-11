#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans;
ll m,a[N],sum[N];
bool check(int x,int e) {
    ll now=sum[e-1]-sum[x-1],tot=a[e]*(e-x);
    ll need=tot-now;
    if(need<=m) return true;
    return false;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    if(a[1]<0) {
        ll tmp=-a[1];
        for(int i=1;i<=n;i++) a[i]+=tmp;
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++) {
        int l=1,r=i-1,best=-1e9;
        while(l<=r) {
            int mid=l+r>>1;
            if(check(mid,i)) {
                r=mid-1;
                best=mid;
            }
            else {
                l=mid+1;
            }
        }
        if(best!=-1e9) ans=max(ans,i-best+1);
    }
    printf("%d",ans);
    return 0;
}
