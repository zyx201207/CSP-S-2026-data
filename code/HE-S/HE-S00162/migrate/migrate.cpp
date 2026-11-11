#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int dp[N][N],w[N][N],a[N];
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) {
		cin>>n>>d;
		memset(dp,127,sizeof(dp));
		memset(w,0,sizeof(w));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<n;i++)dp[i][i+1]=1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)dp[i][j]=1;
				else {
					for(int g=j-1;;g--){
						if(a[j]-a[g]>d)break;
						if(dp[i][j]>dp[i][g]+1){
							dp[i][j]=dp[i][g]+1;
							w[i][j]=1;
						}
						if(dp[i][j]==dp[i][g]+1){
							w[i][j]++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(w[i][j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
