#include<bits/stdc++.h>
#define int long long
int n,m;
int a[500009],sum[500009],ans=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	} 
	int l=1;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l+1)-(sum[i]-sum[l-1])>m) l++;
		ans=std::max(ans,i-l+1);
	}
	std::cout<<ans;
	return 0;
}
