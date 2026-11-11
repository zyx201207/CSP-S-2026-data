#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],d[500005],ans=1,sum=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=1;
    while(l<=r&&r<=n){
        while(sum<=m&&r<=n){
            r++;
            sum+=(r-l)*(a[r]-a[r-1]);
        }
        ans=max(ans,r-l);
        while(sum>m&&l<=r){
            sum=sum-(a[r]-a[l]);
            l++;
        }
    }
    cout<<ans;
    return 0;
}
