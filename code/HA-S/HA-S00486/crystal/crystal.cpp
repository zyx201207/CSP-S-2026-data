#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500009],sum,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=1;
	while(l<=r && r<n){
		if(sum+(r-l+1)*(a[r+1]-a[r])<=m){
			sum+=(r-l+1)*(a[r+1]-a[r]);
			r++;
			ans=max(ans,r-l+1);
		}else{
			sum-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans;
	return 0;
}
