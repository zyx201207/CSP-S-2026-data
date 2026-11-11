#include<bits/stdc++.h>
#define int lint
using namespace std;
using lint=long long;
using llint=__int128;
using ldouble=long double;
const int MAX_N=5010,INF=1e18;
int dp[MAX_N][MAX_N],cnt[MAX_N][MAX_N];
int x[MAX_N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dp[i][j]=INF,cnt[i][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--) if(x[i]-x[j]<=d) dp[j][i]=cnt[j][i]=1;
		for(int j=i+1;j<=n;j++) if(x[j]-x[i]<=d) dp[i][j]=cnt[i][j]=1;
	}
	for(int len=3;len<=n;len++){
		for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			if(dp[l][r]==1) continue;
			for(int k=l;k<=r;k++){
				if(dp[l][r]>dp[l][k]+dp[k][r]){
					dp[l][r]=dp[l][k]+dp[k][r];
					cnt[l][r]=(cnt[l][k]*cnt[k][r]);
				}
				else if(dp[l][r]==dp[l][k]+dp[k][r]){
					dp[l][r]=dp[l][k]+dp[k][r];
					cnt[l][r]+=(cnt[l][k]*cnt[k][r]);
				}
			}
		}
	}
	int ans=0;
	for(int len=1;len<=n;len++){
		for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			if(cnt[l][r]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

