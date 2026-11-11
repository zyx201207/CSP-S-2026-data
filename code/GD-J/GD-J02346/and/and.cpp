#include<bits/stdc++.h>
using namespace std;

int n,m,maxx,dp[200005];

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		maxx=max(maxx,a);
		for(int j=min(m,i);j>1;j--){
			dp[j]=max(dp[j-1]&a,dp[j]);
		}
		dp[1]=maxx;
	}
	
	cout<<dp[m];
	
	return 0;
}
