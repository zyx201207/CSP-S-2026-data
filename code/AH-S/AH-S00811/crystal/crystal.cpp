#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10;

int n,m,a[N],d[N],sum[N];

bool check(int x) {
    x=x-1;
    int ans=INF;
    for(int i=x+1;i<=n;++i) {
        ans=min(ans,(d[i]-d[i-x])-(sum[i]-sum[i-x])*(i-x-1));
    }
    return ans<=m;
}

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;++i) {
        d[i]=d[i-1]+(a[i]-a[i-1])*(i-1);
        sum[i]=sum[i-1]+(a[i]-a[i-1]);
    }
    int l=0,r=n;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    if(l-1==1) cout<<"0";
    else cout<<l-1;
    return 0;
}
