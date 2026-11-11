#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5010;
ll c,T,a[N],dp[N][N],f[N][N],ans;//dp[i][j]表示i~j最短路数量,f表示最短路长度 i<j
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		for(int i=1;i<5005;i++){
			for(int j=1;j<5005;j++) f[i][j]=1e9;
		}
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		ll n,m;cin>>n>>m;
		for(int j=1;j<=n;j++){
			dp[j][j]=1,f[j][j]=0;
			cin>>a[j];
			for(int i=1;i<j;i++){
				if(a[j]-a[i]<=m) dp[i][j]=1,f[i][j]=1;
			}
		}
		for(int j=3;j<=n;j++){
			for(int i=1;i<j-1;i++){
				for(int k=i+1;k<j;k++){
					if(f[i][k]+f[k][j] < f[i][j]){
						f[i][j]=f[i][k]+f[k][j];
						dp[i][j]=1;
					}
					else if(f[i][k]+f[k][j]==f[i][j]){
						dp[i][j]++;
					} 
				}
			}
		}
		ans=0;
		for(int j=1;j<=n;j++){
			for(int i=1;i<=j;i++){
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
