#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],s[N],t,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        ll l=1,r=i,t=i;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) t=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-t+1);
    }
    cout<<ans;
    return 0;
}
