#include<bits/stdc++.h>
using namespace std;
//定义dp[i][j]表示前i个数选择j个数的最优价值
//dp[i][j]=max(dp[k][j-1]&a[i],dp[i][j]);
//时间复杂度O(n^2),空间复杂度O(nm),期望通过50%的数据 
//考虑特殊性质m=n-1,A,B
//当m=n-1时，我们可以考虑&的交换律
//例如a&b=a&b&c&(~c)
// 
long long n;
long long m;
int a[200005];
bool check_a(){
	for(int i=1;i<=n;i++){
		long long cnt=0;
		long long tmp=a[i];
		while(tmp){
			cnt+=(tmp%2);
			tmp>>=1;
		}
		if((1<<cnt)-1!=a[i]){
			return false;
		}
	}
	return true;
}
void solve_a(){
	//考虑贪心，注意到其必定为最小的那一位
	sort(a+1,a+1+n,greater<int>());
	cout<<a[m];
	return; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check_a()){
		solve_a(); 
		return 0;
	}
	//if(check_b()){
	//	solve_b();
	//	return 0;
	//}
	vector<vector<int>> dp(n+1,vector<int>(m+1));
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i][1]=max(dp[i-1][1],a[i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=i;j++){
			dp[i][j]=dp[i-1][j-1]&a[i];
		}
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}
