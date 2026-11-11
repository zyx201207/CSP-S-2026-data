#include <bits/stdc++.h>
using namespace std;
const int M=5e3+10;
int c,t;
int n,d;
int zb[M];
int sum[M];
int dp[M][M];
int ans=0;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		ans=0;
		cin>>n>>d;
//		memset(dp,0x3f3f3f,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>zb[i];
			dp[i][i]=0;
		}
		for(int len=2;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				
				for(int k=l;k<r;k++){
					if(zb[k]-zb[l]>d||zb[r]-zb[k+1]>d)continue;
					dp[l][r]++;
					
				}
			
			}
			
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				//cout<<dp[i][j]<<' ';
				if(dp[i][j]>=n)ans++;
			}
			//cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
} 
