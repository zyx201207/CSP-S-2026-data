#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long sum[500005],ans;
long long sml;
bool check(int x){
	for(int i=x;i<=n;i++){
		long long s=x*a[i]-sum[i]+sum[i-x];
		if(s<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
