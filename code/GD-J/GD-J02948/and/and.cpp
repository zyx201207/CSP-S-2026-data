#include<iostream>
using namespace std;
const long long N=2e5+10,inf=2147483647;
int n,m;int a[N];
long long dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=0;
	}
	dp[0]=inf;
	for(int i=1;i<=n;i++){
		for(int j=min(m,i);j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
			//printf("%d %d %d\n",i,j,dp[j]);
		}
	}
	cout<<dp[m];
} 
/*
4 2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/ 
