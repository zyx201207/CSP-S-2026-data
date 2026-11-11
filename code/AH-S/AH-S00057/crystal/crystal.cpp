#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[789113],he=0,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(ll cnt=0;cnt<m;cnt++){
        for(ll i=n-1;i>0;i--){
            he=0;
            for(ll j=0;j<i;j++){
                he+=(a[i]-a[j]);
            }
            if(he<=m) ans=max(ans,i+1);
        }
    }
    cout<<ans;
    return 0;
}
