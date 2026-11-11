#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
bool check(ll num){
	ll dis=0,ans=1e18;
	for(int i=1;i<num;i++)dis+=a[num]-a[i];
	ans=dis;
	for(int i=num+1;i<=n;i++){
		dis+=num*(a[i]-a[i-1])-(a[i]-a[i-num]);
		ans=min(ans,dis);
	}
	return ans<=m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1); 
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
