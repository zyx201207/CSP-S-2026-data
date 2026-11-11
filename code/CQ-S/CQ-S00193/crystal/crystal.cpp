#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll n,m,i,a[N],pre[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(i=1;i<=n;i++){
        ll l=1,r=i;
        while(l<r){
            ll mid=(l+r)/2;
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%lld\n",ans);
    return 0;
}