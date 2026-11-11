#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
ll n,m,a[N];
ll ans=0,sum[N];
ll cnt;
int main(){
   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
        sum[i]=sum[i+1]+a[i];
    for(int i=1;i<=n;i++){
        ll s=0,ans=n+1;
        ll l=1,r=n;
        while(l<=r){
            ll mid=(l+r)/2ll;
            if(a[i]<a[mid]){
                ans=min(ans,mid);
                r=mid-1;
            }else
                l=mid+1;
        }
        ll tmp=a[i]*ans+sum[ans]-m;
         l=1,r=ans-1;
        while(l<=r){
            ll mid=(l+r)/2ll;
            if(a[i]*mid+sum[mid]>=tmp){
                cnt=max(ans-mid,cnt);
                r=mid-1;
            }else
                l=mid+1;
        }
    }
    cout<<cnt;
    return 0;
}
