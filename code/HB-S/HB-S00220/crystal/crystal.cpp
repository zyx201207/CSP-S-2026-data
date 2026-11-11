#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500005;
ll a[N];
ll n,m;
ll s[N];
ll ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+(a[n]-a[i]);
        //cout<<s[i]<<" ";
    }//cout<<endl;
    for(int i=1;i<=n;i++){
        ll l=0,r=i-1;
        while(l<r){
            ll mid=l+(r-l+1)/2;
            //cout<<i<<" "<<mid<<" "<<s[i-1]-s[i-mid-1]-(mid)*(a[n]-a[i])<<endl;
            if(s[i-1]-s[i-mid-1]-(mid)*(a[n]-a[i])<=m){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        //cout<<l<<endl;
        ans=max(ans,l+1);
    }
    cout<<ans<<endl;
    return 0;
}
