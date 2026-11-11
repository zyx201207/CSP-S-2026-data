#include<bits/stdc++.h>
using namespace std;
const int N=5e3+7;
long long a[N],d,ans;
int dp[N][N],cnt[N][N];
int c,t,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		memset(dp,0x3f,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i][i]=1;cnt[i][i]=1;
			for(int j=i-1;j>=1&&a[i]-a[j]<=d;j--)dp[j][i]=cnt[j][i]=1;//,cout<<j<<" "<<i<<":1 1\n";
		}
		for(int len=3;len<=n;len++){
			for(int i=1;i<=n-len+1;i++){
				int j=i+len-1;
				for(int k=i;k<=j;k++){
					if(dp[i][k]>1e9||dp[k][j]>1e9)continue;
					if(dp[i][k]+dp[k][j]<dp[i][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(dp[i][k]+dp[k][j]==dp[i][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
				if(cnt[i][j]>2)cnt[i][j]=3;
				else if(cnt[i][j]==2)ans++;
				//cout<<i<<" "<<j<<":"<<dp[i][j]<<" "<<cnt[i][j]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
