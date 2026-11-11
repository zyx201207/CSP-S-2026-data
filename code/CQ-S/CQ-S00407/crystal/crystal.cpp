#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r,mid,ans,m,a[500005],sum[500005];
bool check(int k){
	for(int i=k;i<=n;i++)
		if(a[i]*k-sum[i]-sum[i-k]<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

