#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
ll a[500005];
ll cd,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;for(ll i=1;i<=n;i++) cin>>a[i];sort(a+1,a+1+n);
	ll l=1;
	for(ll r=1;r<=n;r++){
		cd+=(r-l)*(a[r]-a[r-1]);
		while(l<=r&&cd>m){
			cd-=a[r]-a[l];
			l++;
		}	
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
