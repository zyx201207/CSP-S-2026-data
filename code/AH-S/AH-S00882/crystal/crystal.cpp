#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],sum[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        ll l=1,r=i,tmp;
        while(l<=r){
            ll mid=(l+r)/2;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
                r=mid-1;
                tmp=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-tmp+1);
    }
    cout<<ans;
    return 0;
}
