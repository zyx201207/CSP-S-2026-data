#include<bits/stdc++.h>

using namespace std;
const int maxn=5005;
const int maxm=5e5+10;
int c,t,n;
long long d;
int dp[maxn][maxn];
long long mindp[maxn][maxn];
long long a[maxn];
long long s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i+k-1<=n;i++){
				int j=i+k-1;
				dp[i][j]=0;
				mindp[i][j]=1e18;
				if(k==1) {
					dp[i][j]=1;
					mindp[i][j]=0;
					continue;
				}
				for(int p=j;p>=i && a[j]-a[p]<=d;--p){
					if(mindp[i][j]==mindp[i][p]+1){
						dp[i][j]+=dp[i][p];
					} 
					else if(mindp[i][j]>mindp[i][p]+1){
						dp[i][j]=dp[i][p];
						mindp[i][j]=mindp[i][p]+1;
					}
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
