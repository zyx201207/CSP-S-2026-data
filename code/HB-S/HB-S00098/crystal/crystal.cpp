#include<bits/stdc++.h>
using namespace std;
long long dp[5005][5005];
long long c[500005],a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1)c[i]=a[i]-a[i-1];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j)dp[i][j]=0;
			else{
				dp[i][j]=dp[i][j-1]+(j-i)*c[j];
			}
			if(dp[i][j]<=m)maxn=max(maxn,j-i+1);
		}
	}
	cout<<maxn;
	return 0;
}
