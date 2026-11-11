#include<bits/stdc++.h>
#include<windows.h>
#define int long long
const int N=5e5+10;
//引理1：绝对有一个为不变值
int n,m;
int res=1;
int a[N],sum[N];

void solve(){
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i]; 
	}	
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		//二分
		int l=1,r=i-1,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
				r=mid-1;
				ans=i-mid+1;
			}
			else{
				l=mid+1;
			}
		} 
		res=std::max(res,ans);
	}
	std::cout<<res<<'\n';
	return ;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
