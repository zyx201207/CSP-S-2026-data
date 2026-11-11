#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=0;
long long a[400000],vis[400000],dp[400000];
int gcd(int a,int b){
	long long ans=0;
	int x1[32],x2[32];
	for(int i=1;i<=32;i++){
		x1[i]=0;
		x2[i]=0;
	} 
	int idx1=0,idx2=0;
	while(a){
		idx1++;
		x1[idx1]=a%2;
		a/=2;
		
	}
	while(b){
		idx2++;
		x2[idx2]=b%2;
		b/=2;
	}
//	for(int i=1;i<=idx1;i++){
//		cout<<x1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=idx2;i++){
//		cout<<x2[i]<<" ";
//	}
	long long k=1;
	for(int i=1;i<=min(idx1,idx2);i++){
		if(x1[i]==x2[i]&&x1[i]==1){
			ans+=k;
		}
		k*=2;
	}
	return ans;
} 
void dfs(int step){
	if(step==m+1){
		long long sum=dp[1];
	//	cout<<dp[1]<<" ";
		for(int i=2;i<=m;i++){
		//	cout<<dp[i]<<" ";
			sum=gcd(sum,dp[i]);
		}
	//	cout<<sum<<endl;
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&dp[step-1]<=a[i]){
			vis[i]=1;
			dp[step]=a[i];
			dfs(step+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
//	cout<<gcd(12,12)<<" ";
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1);
//	cout<<111;
	cout<<maxn;
	return 0;
} 
