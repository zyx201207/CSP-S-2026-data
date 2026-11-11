#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,mx;
int a[N],sum[N];
bool check(int l,int r){
    return ((r-l+1)*a[r]-(sum[r]-sum[l-1]))<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid,ans=i;
        while(l<=r){
            mid=l+r>>1;
            if(check(mid,i)) r=mid-1,ans=mid;
            else l=mid+1;
        }
        mx=max(mx,i-ans+1);
    }
    cout<<mx;
    return 0;
}
