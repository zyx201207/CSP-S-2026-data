#include<bits/stdc++.h>
#define ll long long
#define rep(a,b,c) for(ll (a)=(b);(a)<=(c);(a)++)
#define wep(a,b,c) for(ll (a)=(b);(a)>=(c);(a)--)
#define tep(a,b) for(auto &(a):(b))
using namespace std;
const ll N=6e5+5;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,cnt1=0,cnt=0,ans=1;
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
		if(i==1)
			continue;
	}
	sort(a+1,a+1+n);
	rep(i,2,n){
		cnt1+=a[i]-a[1];
		cnt=i*(a[i]-a[1])-cnt1;
		sum[i]=sum[i-1]+a[i]-a[1];
		ll l=0,r=i-1;
		while(l<r-1){
			ll mid=(l+r)/2;
//			cout<<"mid="<<mid<<endl;
			if(sum[mid]<=m+mid*(a[i]-a[1])-cnt){
				r=mid;
			}
			else{
				l=mid;
			}
		}
		if(sum[l]<=m+l*(a[i]-a[1])-cnt)
			ans=max(ans,i-l);
		else if(sum[l+1]<=m+(l+1)*(a[i]-a[1])-cnt){
			ans=max(ans,i-l-1);
		}
		else{
			ans=max(ans,i-l-2);
		}
//		cout<<"i="<<i<<",ans="<<i-l<<",cnt="<<cnt<<endl;
	}
	printf("%lld",ans);
	return 0;
}
