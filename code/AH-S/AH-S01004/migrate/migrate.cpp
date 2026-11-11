#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[305][305],x[2000005],dp2[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		bool flag=true;
		int flag2=0;
		int val=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==2) val=x[i]-x[i-1];
			else if(i>2&&x[i]-x[i-1]!=val) flag=false;
		}
		if(n==1){
			cout<<"0\n";
			continue;
		}
		if(flag){
			int x=d/val;
			if(x==1||x==0||n-x-x+1<0) cout<<"0\n";
			else cout<<n-x-x+1<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) if(x[i]-x[1]<=d&&x[n]-x[i]<=d) flag2++;
		if(flag2==1){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=1e9,dp2[i][j]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(abs(x[j]-x[i])<=d) dp[i][j]=1;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dp[i][j]>dp[i][k]+dp[k][i]){
						dp[i][j]=dp[i][k]+dp[k][j];
						dp2[i][j]=1;
					}
					else if(dp[i][j]==dp[i][k]+dp[k][j]) dp2[i][j]++;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(dp2[i][j]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
