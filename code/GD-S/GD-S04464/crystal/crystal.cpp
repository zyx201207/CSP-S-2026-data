#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005],sum[500005];
map<long long,long long> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,++mp[a[i]]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		long long l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)/2;
			long long t=sum[i]-sum[mid-1];
			if((i-mid+1)*a[i]-t<=m) ans=max(ans,i-mid+1),r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
