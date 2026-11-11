#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],ans;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1,l=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        while(l<=i&&m<a[i]*(i-l+1)-(sum[i]-sum[l-1]))l++;
        ans=max(i-l+1,ans);
    }
    cout<<ans<<endl;
    return 0;
}
//Oct31==Dec25?
