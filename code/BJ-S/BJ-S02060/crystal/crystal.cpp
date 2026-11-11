#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll k=a[n/2];
	for(ll i=n;i>=1;i--){
        ll s=0;
        for(ll j=1;j<=i;j++){
            s+=a[i]-a[j];
        }
        if(s<=m&&ans<i) ans=i;
	}
	cout<<ans;
	return 0;
}
