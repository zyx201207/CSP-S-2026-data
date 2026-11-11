#include <bits/stdc++.h>
using namespace std;
long long a[500050],qz[500050];
long long minnum(int x,int n){
	long long ans=1e18;
	for(int xs=x;xs<=n;xs++){
		ans=min(ans,a[xs]*x-qz[xs]+qz[xs-x]);
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int xs=1;xs<=n;xs++){
		scanf("%lld",&a[xs]);
	}
	sort(a+1,a+1+n);
	for(int xs=1;xs<=n;xs++){
		qz[xs]=qz[xs-1]+a[xs];
	}
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(minnum(mid,n)<=m){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
