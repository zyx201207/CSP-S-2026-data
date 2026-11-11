#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500100],s[500100],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1); 
	for(int i=1; i<=n; i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n; 
	while(l<=r){
 		int mid=(l+r)/2;
 		int sum=1e18;
		for(int i=mid; i<=n; i++){
			sum=min(sum,a[i]*mid-(s[i]-s[i-mid]));
		
		}
		if(sum<=m){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
/*
Oct31==Dec25?
*/
