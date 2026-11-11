#include <bits/stdc++.h>
using namespace std;
int dp[793][793][793];
int n,m,a[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==m){
		maxx=a[1];
		for(int i=2;i<=n;i++)
			maxx&=a[i];
	}
	else if(n==m+1){
		maxx=a[1];
		for(int i=2;i<=n;i++)
			maxx&=a[i];
		int awa=maxx;
		maxx=0;
		for(int i=1;i<=n;i++)
			maxx=max(maxx,awa&a[i]);
	}
	else if(n<793){
		for(int len=m;len<=n;len++)
			for(int l=1;l<=n-len+1;l++){
				int r=l+len-1;
				for(int i=l;i<=r;i++)
					dp[l][r][1]=max(dp[l][r][1],a[i]);
				for(int i=2;i<=m;i++){
					for(int j=1;j<i;j++)
						for(int k=l;k<r;k++)
							dp[l][r][i]=max(dp[l][r][i],dp[l][k][i]&dp[k+1][r][j-i]);
				}
				maxx=max(maxx,dp[l][r][m]);
			}
	}
	cout<<maxx;
	return 0;
}
