#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1000010],high[1000010],ans;
ll sum[1000010];
ll check(ll L,ll R){
	ll s1=sum[L],s2=sum[R],s3=(R-L)*(high[n]-high[R]);
	ll res=s1-s2-s3;
	return res;
}
ll mid_search(ll t){
	ll l=1,r=t,res=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(t-mid+1,t)<=m){
			l=mid+1;res=mid;
		}else{
			r=mid-1;
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--){
		high[i]=a[i]-a[1];
		sum[i]=(high[n]-high[i])+sum[i+1];
	}
	for(ll i=1;i<=n;i++){
		ans=max(ans,mid_search(i));
	}
	cout<<ans;
	return 0;
}
