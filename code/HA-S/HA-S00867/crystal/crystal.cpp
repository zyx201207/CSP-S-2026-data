#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n,m,a[500009],b[500009],x,l=1,r,mid,cost,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    //a[0]=(ll)(1e12+1);
    ll i=1;
    for(;i<=n;i++){
        for(;a[i]==a[i+1];i++);
        r=i;
        for(;r>l;){
            mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-b[i]+b[mid-1]>m){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        ans=max(ans,i-mid+1);
    }
    printf("%lld",ans);
    return 0;
}
