#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll n,m,a[N],pre[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
	}
	for(ll i=1;i<=n;++i){
//		ll sum=0,tot=0,p=i;
//		for(j=i-1;j>=1;--j){
//			tot+=a[i]-a[j];
//			if(tot>m)break;
//			else p=j;
//		}
//		ans=max(ans,i-p+1);
		ll l=1,r=i-1,o=i;
		while(l<=r){
			ll mid=(l+r)/2,len=i-mid+1;
			if(len*a[i]-(pre[i]-pre[mid-1])<=m){
				r=mid-1,o=mid;
			}
			else l=mid+1;
		}//o是最左满足差和小于等于m 
		ans=max(ans,i-o+1);
	}
	cout<<ans;
	return 0;
}
