#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
long long c,T,n,d,x[N],dp[5007][5007],ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<4) {
			cout<<0<<endl;
			continue;
		}
		for(int len=1;len<=n;len++) {
			for(int l=1;l<=n;l++) {
				int r=l+len-1;
				if(r>n) break;
				dp[l][r]=0x3ffffff;
				int cnt=1;
				if(x[r]-x[l]<=d) dp[l][r]=1;
				else {
					for(int k=l+1;k<r;k++) 
						if(dp[l][k]!=0&&dp[k][r]!=0) {
							if(dp[l][k]+dp[k][r]<dp[l][r]) {
								dp[l][r]=dp[l][k]+dp[k][r];
								cnt=1;
							} else if(dp[l][k]+dp[k][r]==dp[l][r]) cnt++;
						}
				}
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
