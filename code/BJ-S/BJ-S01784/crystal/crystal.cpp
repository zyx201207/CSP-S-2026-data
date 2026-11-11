#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans,a[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;++i){
        int l=1,r=i,best=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
                best=mid;
                r=mid-1;
            }else l=mid+1;
        }ans=max(ans,i-best+1);
    }cout<<ans;
    return 0;
}