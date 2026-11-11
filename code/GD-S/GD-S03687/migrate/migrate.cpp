#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[305][305];
ll f[305][305];
ll n,m;
ll x[305];
ll c,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(labs(x[i]-x[j]) <= m){
					dp[i][j] = 1;
					f[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i==k || j==k || i==j)continue;
					if(dp[i][k]+dp[k][j] < dp[i][j]){
						dp[i][j] = dp[i][k]+dp[k][j];
						f[i][j] = f[i][k]*f[k][j];
					}else if(dp[i][k]+dp[k][j] == dp[i][j]){
						f[i][j] = f[i][j]+f[i][k]*f[k][j]; 
					}
				}
			}
		}
		ll cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f[i][j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
