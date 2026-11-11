#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll l=1,r=1,sum=0,ans;
	for(;r<=n;){
		if(sum+(a[l]-a[r])<=m){
			sum+=(a[l]-a[r]);
			r++;
		}
		else{
			ans=max(ans,r-l);
			ll cnt=a[l]-a[l+1];
			sum-=cnt*(r-l-1);
			l++;
		}
	}
	if(sum<=m){
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
