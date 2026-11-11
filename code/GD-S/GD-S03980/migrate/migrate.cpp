#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,M=1e18;
int c,T,n,d,x[N],dp[N][N],f[N][N],ans,dp2[N*N],f2[N*N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dp[i][j]=0;
				else dp[i][j]=M;
				f[i][j]=0;
			}
			dp2[i]=M;
			f2[i]=0;
		}
		int cek=0,flag=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1){
				if(!cek) cek=x[i]-x[i-1];
				if(x[i]-x[i-1]!=cek) flag=0;
			}
		}
		if(flag){
			dp2[2]=1;
			for(int i=2;i<=n;i++){
				for(int j=i-1;j>=1;j--){
					if(x[i]-x[j]>d) break;
					if(dp2[i]==dp2[j]+1){
						f2[i]++;
					}
					else if(dp[i]>dp[j]+1){
						f2[i]=1;
						dp2[i]=dp2[j]+1;
					}
				}
				if(f2[i]==2) ans+=(n-i+1);
			}
			cout<<ans<<endl;
			continue;
		}
		for(int len=2;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				for(int k=r-1;k>=l;k--){
					if((x[r]-x[k])>d) break;
					if(dp[l][r]==dp[l][k]+1){
						f[l][r]++;
					}
					else if(dp[l][r]>dp[l][k]+1){
						f[l][r]=1;
						dp[l][r]=dp[l][k]+1; 
					}
				}
				if(f[l][r]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
