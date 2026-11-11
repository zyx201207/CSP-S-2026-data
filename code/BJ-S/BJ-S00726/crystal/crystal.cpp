#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500010],m,sum[500010],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
    for(int i=n;i>=1;i--){
        ll x=a[i]*i-sum[i];
        ll l=0,r=i;
        while(l<r){
            ll mid=(l+r)/2;
            if(x+sum[mid]-a[i]*mid<=m) ans=max(ans,i-mid),r=mid;
            else l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
