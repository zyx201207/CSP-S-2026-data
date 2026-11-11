#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10,INF=0x3f3f3f3f3f3f3f3f;
LL n,m,a[N];
bool check(LL x){
   LL sum=0,ans=INF;
   for(LL i=1;i<=n;i++){
        sum+=a[i];
        if(i>=x){
            ans=min(ans,a[i]*x-sum);
            sum-=a[i-x+1];
        }

   }
   return ans<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    LL l=1,r=n+1;
    while(l<r){
        LL mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l-1;
    return 0;
}
