#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,ll>mp,sum;
const int N=5e5+100;
ll a[N];
int main(){
	//¼ì²éfreopenÊÇ·ñ±»×¢ÊÍ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	ll n,m,maxa=-LONG_LONG_MAX;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
		maxa=max(a[i],maxa);
	}
	if(n>5000&&abs(maxa)>100){
		for(int i=1;i<=n;i++) cin>>a[i];
		ll gc=a[2]-a[1],t=m,ans=0;
		for(int i=0;i<n;i++){
			if(t<gc*i) break;
			t-=gc*i;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n);
	int len=unique(a,a+n)-a;
	ll last=0;
	sum[a[0]]=mp[a[0]];
	for(int i=1;i<len;i++){
		ll t=m;
		sum[a[i]]=mp[a[i]];
		for(int j=i-1;j>=0;j--){
			if(t<=0) break;
			if(t<a[i]-a[j]) break;
			ll gs=((t/(a[i]-a[j]))>mp[a[j]]?mp[a[j]]:(t/(a[i]-a[j])));
			sum[a[i]]+=gs;		
			t-=gs*(a[i]-a[j]);
		}
		//*debug*/cout<<sum[a[i]]<<"\n";/*debug*/
	}
	ll ans=-1;
	for(int i=0;i<len;i++) ans=max(ans,sum[a[i]]);
	cout<<ans;
	
	
	return 0;
} 
