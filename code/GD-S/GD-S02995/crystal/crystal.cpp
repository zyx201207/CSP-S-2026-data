#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],dp[10010][10010],m,n,x,sum,l,maxx=-999;
void find(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			if(b[i]<=j)dp[i][j]=max(dp[i-1][j],dp[i-1][j-b[i]]+1);
		}
	}
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[i]-a[j];
		}
		find();
		maxx=max(dp[n][m],maxx);
	}
	cout<<maxx;
	return 0;
}
