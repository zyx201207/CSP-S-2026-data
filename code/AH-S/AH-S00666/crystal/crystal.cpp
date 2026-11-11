#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500000+10;
ll n,m,a[N],sum[N],l,r;
bool ok(int x) {
    for(int i=1;i+x-1<=n;i++) {
        if(a[i+x-1]*(x-1)-(sum[i+x-2]-sum[i-1])<=m) return 1;
    }
    return 0;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    l=1;
    r=n;
    while(l<r) {
        ll mid=(l+r)/2;
        if(ok(mid)==1) {
            l=mid;
        }
        else r=mid-1;
        if(r-l==1&&ok(r)==0&&ok(l)==1) break;
        if(r-l==1&&ok(r)==1) {
            l=r;
            break;
        }
    }
    cout<<l;
    return 0;
}
