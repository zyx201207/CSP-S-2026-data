#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],ans=1;
__int128 sum[500020],b[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[0]=a[1];
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
        sum[i]=sum[i-1]+b[i]*(i-1);
    }
    ll l=1;
    for(int r=2;r<=n;r++){
        while(l<r&&sum[r]-sum[l]-(a[r]-a[l])*(l-1)>m){
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
