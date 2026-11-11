#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,m,a[2000001],dp[2000001],y[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];	
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			y[i]=0;
			for(int i=1;i<=n;i++){
				dp[i]=0;
			}
			for(int j=i+1;j<=n;j++){
				long long g=2e9;
				if(j<=m+i){
					y[j]=1;
					dp[j]=1;
				}
				else{
					long long minn=y[j-m];
					for(int k=j-1;k>=j-m;k--){
						if(y[k]==minn&&a[k]+m>=a[j]){
							dp[j]++;
						} 
					}
					for(int k=j-1;k>=j-m;k--){
						if(a[k]+m>=a[j]||j-k==1){
							g=min(g,y[k]+1);
						}
					}
					y[j]=g;
				}
				
			}
			for(int j=i+1;j<=n;j++){
				if(dp[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
