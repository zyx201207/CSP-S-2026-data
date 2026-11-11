#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;ll m,a[N],sum[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        ll L=1,R=i;
        while(L<R){
            ll mid=(L+R)>>1;
            if(1ll*a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)R=mid;
            else L=mid+1;
        }
        ans=max(ans,(ll)(i-L+1));
    }
    cout<<ans;
    return 0;
}