#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	auto check=[&](int x)->bool{
		x+1;
		while(x){
			if(x&1)return 0;
			x>>=1; 
		}
		return 1;
	};
	vector<int>a(n);
	bool f=1;
	int mx=0;
	for(auto &x:a){
		cin>>x;
		f&=check(x);
	}
	if(f){
		sort(a.begin(),a.end(),greater<int>());
		cout<<a[m-1];
		return 0;
	}
	vector<vector<int>>dp(n+1,vector<int>(m+1));
	for(int i=0;i<n;++i){
		dp[i][1]=a[i];
		for(int j=1;j<=m;++j){
			for(int k=0;k<i;++k){
				dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i)ans=max(ans,dp[i][m]);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
