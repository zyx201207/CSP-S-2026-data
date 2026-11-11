#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500010],cnt,ans=LLONG_MIN;
ll check(ll x){
	ll sum=0;
	for(int i=x;i>=1;i--){
		if(sum<=m){
			sum+=a[x]-a[i];
			cnt++;
		}else{
			return cnt;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l<=r){
		cnt=0;
		ll mid=l+(r-l)/2;
		if(!check(mid)){
			ans=max(ans,cnt);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
