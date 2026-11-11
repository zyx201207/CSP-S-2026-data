#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],sum[500010],l,r,maxa,mina,la;
bool f1=1,f2=1;
bool check(ll x){
	ll cnt1=0,cnt=INT_MAX;
	for(int i=x;i<=n;i++){
		for(int j=i-x+1;j<=i;j++){
			cnt1+=a[i]-a[j];
		}
		cnt=min(cnt,cnt1);
	}
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f1=0;
		if(i>=3)if(a[i]-a[i-1]!=a[i-1]-a[i-2])f2=0;
		sum[i]=sum[i-1]+a[i];
	}
	if(f1){
		ll ans=1;
		for(ans=1;ans<=n;ans++){
			if(sum[ans]>=m)break;
		}
		cout<<ans+1;
		return 0;
	}else if(f2){
		ll ans=1,cnt1=0;
		for(ans=1;ans<=n;ans++){
			cnt1+=ans*(a[2]-a[1]);
			if(cnt1>m)break;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(mid)){
			la=mid,l=mid+1;
		}else r=mid-1;
	}
	cout<<la;
	return 0;
}
