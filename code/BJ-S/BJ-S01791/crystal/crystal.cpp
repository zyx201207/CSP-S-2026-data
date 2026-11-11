#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
const int N=5e5+5;
int n,ans; ll m,a[N],s[N];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,1,n) s[i]=s[i-1]+a[i];
    rep(i,1,n) {
        int l=1,r=i-1,na=i;
        while(l<=r) {
            int mid=l+r>>1;
            if((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m) na=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-na+1);
    }
    cout<<ans;
    //cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
    return 0;
}
