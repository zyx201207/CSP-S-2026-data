#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<int> lis;
vector<vector<int>> dp;
int ans=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	lis.resize(n+1);
	for(int i=1;i<=n;i++)
		cin>>lis[i];
	bool f=0;
	dp.resize(n+1,vector<int>(n+1,LLONG_MAX));
	dp[1][1]=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			int fir=dp[i-1][j],sec=dp[i-1][j-1]+(j-1)*(lis[i]-lis[i-1]);
			dp[i][j]=min(fir,sec);
			if(m<dp[i][j])
				break;
			ans=max(ans,j);
		}
	}
	cout<<ans;
	return 0;
}
