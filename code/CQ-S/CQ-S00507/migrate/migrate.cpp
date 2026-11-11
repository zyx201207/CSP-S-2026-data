#include<bits/stdc++.h>
using namespace std;
long long c[2000009],dy[2000009],dp[6][2000009];
int main(){
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long t;
	cin>>t;
	cin>>t;
	while(t--){
		long long a,b,ra=0;
		cin>>a>>b;
		for(long long i=1;i<=a;i++)cin>>c[i];
		for(long long i=1,j=1;i<=a;i++){
			while(j<a&&c[j+1]<=c[i]+b)j++;
			dy[i]=j;
//			cerr<<dy[i]<<endl;
		}
		for(long long i=a;i>=1;i--){
			if(dy[i]!=i){
				if(dy[i]-i==1&&dy[i-1]-i!=1)dp[3][i]=dp[1][i]=dp[2][i]=dp[0][i+1],dp[4][i]=dp[4][i+1],dp[5][i]=dp[5][i+1];
				else{
					if(dy[i]!=dy[i-1])dp[4][i]=dp[4][dy[i]]+dy[i]-max(i,dy[i-1])-1;
					else dp[4][i]=0;
					dp[5][i]=dp[4][dy[i]]+dy[i]-i-1;
					if(dy[i]-dy[i-1]>=2)dp[3][i]=dp[1][dy[i]];
					else if(dy[i]-dy[i-1]==1)dp[3][i]=dp[3][dy[i]];
					else dp[3][i]=0;
					if(dy[i]-dy[i-1]>=2)dp[2][i]=dp[1][dy[i]];
					else if(dy[i]-dy[i-1]==1)dp[2][i]=dp[3][dy[i]];
					else dp[2][i]=0;
					if(dy[i]-dy[i-1]>=2)dp[1][i]=dp[1][dy[i]];
					else if(dy[i]-dy[i-1]==1)dp[1][i]=dp[2][dy[i]]-1;
					else{
						if(dy[i-2]==dy[i])dp[1][i]=0;
						else if(dy[i]==i+1)dp[1][i]=dp[5][dy[i]]-1;
						else dp[1][i]=dp[4][dy[i]]-1;
					}
					dp[1][i]=dp[1][i]+dy[i-1]-max(i,dy[i-2]);
				}
				if(dy[i]-i>=2)dp[0][i]=dp[1][dy[i]];
				else if(dy[i]-i==1)dp[0][i]=dp[0][dy[i]];
			}
			dp[2][i]++,dp[4][i]++,dp[5][i]++;
			ra+=dp[0][i];
		}
		cout<<ra<<endl;
		for(long long i=1;i<=a;i++)dp[0][i]=dp[1][i]=dp[2][i]=dp[3][i]=dp[4][i]=dp[5][i]=dy[i]=c[i]=0;
	}
	return 0;
}
