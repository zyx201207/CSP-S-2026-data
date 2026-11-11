#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,maxx;
int g[200005],dp[200005]={0};
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	sort(g+1,g+n+1);
	dp[0]=g[1];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			int sum=dp[j-i];
			sum &= g[i];
			dp[j]=max(dp[j],sum);
		}
	}
	
	int sum=g[n];
	for(int i=n-1;i>n-m;i--){
		sum&=g[i];
	} 
	cout<<max(dp[m],sum);
	return 0;
}
