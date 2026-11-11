#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[600000],ans=-1e18,k=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        m-=(i-k)*(a[i]-a[i-1]);
        for(ll j=k;j<i;j++){
            if(m<0){
                m+=(a[i]-a[j]);
                k++;
            }
            else{
                break;
            }
        }
        ans=max(ans,i-k+1);
        if(m<0){
            break;
        }
    }
    cout<<ans;
    return 0;
}
