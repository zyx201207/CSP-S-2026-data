#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,a[N],sum[N];
bool check(int r,int len){
	return (r-len+1>0) && (len*a[r]-sum[r]+sum[r-len]<=m); 
}
ll len(int x){
	ll l=1,r=x;
	ll ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(x,mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,len(i));
	}
	cout<<ans;
	return 0;
}
