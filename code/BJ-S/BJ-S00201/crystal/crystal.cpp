#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=5e5+10;
ll a[N],q[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(ll i=2;i<=n;i++){
        q[i]=q[i-1]+(a[i]-a[i-1])*(i-1);
    }
    
    ll ans=1;
    for(ll s=1;s<=n;s++){
        ll l=s+1,r=n,j=s;
        while(l<=r){
            ll mid=(l+r)/2;
            ll t=q[mid]-q[s]-(s-1)*(a[mid]-a[s]);

            if(t<=m) j=mid,l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,j-s+1);
    }
    cout<<ans<<endl;
    return 0;
}