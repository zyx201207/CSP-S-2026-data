#include <bits/stdc++.h>
using namespace std;
const int M=4e3+10;
long long n,ans=0;
long long maxx=INT_MIN;
long long m;
int mp[M];
int dp[M][M];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	memset(dp,0x3f3f3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		cin>>mp[i];
		dp[i][i]=0;
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			
			for(int k=l;k<r;k++){
				if(dp[l][k]>m||dp[k+1][r]>m)continue;
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+(k-l+1)*(mp[r]-mp[k]));
			}
			
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(dp[i][j]<=m)maxx=max(maxx,j-i+1);
		}
	}
	cout<<maxx;
	return 0;
} 
