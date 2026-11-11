#include<bits/stdc++.h>
#define int long long
int n,m,ans1=INT_MIN,k;
int a[1000010];

bool check(int mid){
	int sum=0,tmp=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=mid) sum+=(mid-a[i]),tmp++;
	}
	if(sum<=m) ans1=std::max(ans1,tmp);
	return sum<=m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin>>n>>m;
	int l=-1e12,r=1e12;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	std::sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++) std::cout<<a[i]<<' ';
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	int tmp=std::upper_bound(a+1,a+n+1,l)-a-1,ans2=0;
	for(int i=n;i>=1;i--){
		if(m>0&&a[i]<=a[tmp]){
			m-=(a[tmp]-a[i]);
			ans2++;
		}
	}
	std::cout<<std::max(ans1,ans2-(m<0));
	return 0;
} 
