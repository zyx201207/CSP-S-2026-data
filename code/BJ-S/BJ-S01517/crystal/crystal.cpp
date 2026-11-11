#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],q[500005],allans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)q[i]=q[i-1]+a[i];
    for(ll i=1;i<=n;i++){
        ll l=1,r=i,ans=i;
        while(l<=r){
            ll mid=(l+r)/2;
            if(a[i]*(i-mid+1)-(q[i]-q[mid-1])<=m)r=mid-1,ans=mid;
            else l=mid+1;
        }
        allans=max(allans,i-ans+1);
    }
    cout<<allans<<endl;
    return 0;
}
