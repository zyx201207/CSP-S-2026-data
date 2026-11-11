#include<bits/stdc++.h> 
using namespace std;
long long m;
long long n; 
long long sum[100007];
long long a[1000007]; 
long long Max=1;
long long dp[5005][5005];//以I为基准,操作次数最多为J的最大值 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	} 
	dp[1][1]=1;
	sort(a+1,a+1+n);
	for(long long j=2;j<=n;j++){
		if(m>=a[j]*(j-1)-sum[j-1]) Max=max(Max,j);
	}
	cout<<Max;
	return 0;
} 
