#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,l=1,used,getback,ans=1,a[1000000],d[1000000];
int main(){
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }sort(a,a+n);
    for(int i=1;i<n;i++){
        d[i]=a[i]-a[i-1];
    }for(ll r=1;r<n;r++){
        used+=(r-l+1)*d[r];
        getback+=d[r];
        while(used>m){
            used-=getback;getback-=d[l++];
        }ans=max(ans,r-l+2);
    }cout<<ans;
    return 0;
}
