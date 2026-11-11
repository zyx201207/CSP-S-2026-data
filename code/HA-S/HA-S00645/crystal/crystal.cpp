#include<bits/stdc++.h>
using namespace std;
const int N=5.1e5;
#define ll long long
ll n,m,a[N],sum[N],ans=-3e18;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=n;i>=1;i--){
		ll l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

