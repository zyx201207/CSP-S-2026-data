#include<bits/stdc++.h>
using namespace std;
const long long Max=200000005;
const long long MaxN=1000005;
int dp[MaxN];
int v[Max];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//long long sum=0;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			v[i]=a[i]&a[j];
			//sum++;
			//cout<<"v="<<v[i]<<" ";
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>0;j--){
			dp[j]=max(dp[j],dp[j-1]+v[i]);
			//cout<<"dp[]="<<dp[j]<<"   ";
			//printf("dp[%d]=%d",j,dp[j]);
		}
	}
	cout<<dp[1];
	return 0;
}
