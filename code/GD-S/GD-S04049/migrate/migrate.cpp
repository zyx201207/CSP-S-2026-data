#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int a[2000005];
short dp[505][505][505];
void solve(){
	cin>>n>>d;
	for (int i=1;i<=n;cin>>a[i++]);
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)for (int k=i;k<=n;k++)dp[i][j][k]=0;
	for (int i=1;i<=n;i++){
		for (int j=i+2;j<=n;j++){
			for (int k=i+1;k<j;k++){
				if (a[k]-a[i]<=d&&a[j]-a[k]<=d)dp[2][i][j]++;
			}
		}
	}
	for (int len=3;len<=n;len++){
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if (dp[len][i][j]==3)continue;
				for (int k=i+1;k<=j;k++){
					if (a[k]-a[i]<=d)dp[len][i][j]=min(3,dp[len][i][j]+dp[len-1][k][j]);
					if (a[j]-a[k]<=d)dp[len][i][j]=min(3,dp[len][i][j]+dp[len-1][i][k]);
				}
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i+2;j<=n;j++){
			if (a[j]-a[i]<=d)continue;
			for (int len=2;len<=n;len++){
				if (dp[len][i][j]){
					if (dp[len][i][j]==2)ans++;
					break;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	int _c,t;
	cin>>_c>>t;
	while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();while(t--)solve();
	if (1+1==3){
		cout<<"qing cang shuai mai shi yi dao ji ju si wei mei gan yu shen du de ti";
	}
	return 0;
}
