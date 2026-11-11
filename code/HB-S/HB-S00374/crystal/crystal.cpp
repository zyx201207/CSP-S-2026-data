#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[550000],ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        ll j,x=m;
        for(j=i;j>0;j--){
            if(a[i]-a[j]<=x)x-=(a[i]-a[j]);
            else break;
        }
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
