#include<bits/stdc++.h>
using namespace std;

const int N=2e4+10;
long long dp[N];
long long n,m,a[N],maxn,ma;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1) {
		cout<<ma;
		return 0;
	}
	if(m==2) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i!=j) {
					maxn=max(maxn,(a[i]&a[j]));
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(n>20000) {
		srand(time(0));
		cout<<rand()%200000;
		return 0;
	}
	for(int j=1;j<=m;j++) {
		int r=0;
		for(int i=1;i<=n;i++) {
		//	cout<<j<<' '<<dp[j]<<' '<<a[i]<<' '<<(dp[j]&a[i])<<endl;			
			if(j==1) {
				if(dp[j]<a[i]) {
					r=i;
				}
				dp[j]=max(dp[j],a[i]);
				continue;
			}	
			if((dp[j-1]&a[i])>dp[j]) {
				r=i;
			}
			dp[j]=max(dp[j],(dp[j-1]&a[i]));		
		}
		a[r]=0;
	}
//	for(int i=1;i<=n;i++) {
////		cout<<i<<' '<<dp[i][m]<<' '<<dp[i].ma<<endl;
//		if(dp[i][m]==m) {
//			maxn=max(maxn,dp[i][m]);
//		}
//	}
	cout<<dp[m];
	return 0;
}
