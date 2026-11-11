//GZ-S00138 贵阳市第一中学 张轩睿 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,INF=1e18;
int n,m;
int a[N];
int dp[N];
int check(int x){
	int res=INF;
	memset(dp,0,sizeof(dp));
	for (int i=1;i<x;i++)
		dp[x-1]+=(a[x-1]-a[i]);
	for (int i=x;i<=n;i++){
		dp[i]=dp[i-1]+x*(a[i]-a[i-1])-(a[i]-a[i-x]);
		res=min(res,dp[i]);
	}
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int left=1,right=n,ans=1;
	while (left<=right){
		int mid=left+right>>1;
		if (check(mid)<=m){
			left=mid+1;
			ans=mid;
		}else right=mid-1;
	}
	cout<<ans;
	return 0;
}
